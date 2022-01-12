// Fill out your copyright notice in the Description page of Project Settings.


#include "TCPSocket.h"
#include <string>
#include "../Entity/GameMap.h"
#include "../Entity/GamePlayer.h"
#include "../InputServices/InputService.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
ATCPSocket::ATCPSocket()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	SetActorHiddenInGame(true);
}

ATCPSocket::~ATCPSocket()
{
	UE_LOG(LogTemp, Warning, TEXT("TCP socket deleted"));
}

// Called when the game starts or when spawned
void ATCPSocket::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATCPSocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ATCPSocket::LaunchTCP(FString Port, AGamePlayer* player)
{
	Player = player;
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Port);
	if (!StartTCPReceiver("SocketListener", "127.0.0.1", FCString::Atoi(*Port)))
	{
		UE_LOG(LogTemp, Warning, TEXT("Failed to start Socket"));
		return false;
	}
	UE_LOG(LogTemp, Warning, TEXT("Socket started succesfully"));
	UE_LOG(LogTemp, Warning, TEXT("------------------------------------------------------------"));
	return true;
}

void ATCPSocket::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	UWorld* World = GetWorld();

	GetWorld()->GetTimerManager().ClearTimer(TCPConnectionListenerTimerHandle);
	GetWorld()->GetTimerManager().ClearTimer(TCPSocketListenerTimerHandle);

	if (ConnectionSocket != NULL) {
		ConnectionSocket->Close();
	}
	if (ListenerSocket != NULL) {
		ListenerSocket->Close();
	}

}

//----------------------------------------------------------------------------------------------
////Start TCP reciver
bool ATCPSocket::StartTCPReceiver(
	const FString& YourChosenSocketName, const FString& TheIP, const int32 ThePort)
{
	ListenerSocket = CreateTCPConnectionListener(YourChosenSocketName, TheIP, ThePort);

	//Not created?
	if (!ListenerSocket)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("StartTCPReceiver>> Listen socket could not be created! ~> %s %d"), *TheIP, ThePort));
		return false;
	}

	//Start the Listener! //thread this eventually
	UWorld* World = GetWorld();
	World->GetTimerManager().SetTimer(TCPConnectionListenerTimerHandle, this, &ATCPSocket::TCPConnectionListener, 1.0f, true);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("StartTCPReceiver>> Listen socket created")));
	return true;
}

////----------------------------------------------------------------------------------------------
//////Format IP String as Number Parts
bool ATCPSocket::FormatIP4ToNumber(const FString& TheIP, uint8(&Out)[4])
{
	////IP Formatting
	FString NewIP = TheIP.Replace(TEXT(" "), TEXT(""));

	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//						   IP 4 Parts

	//String Parts
	TArray<FString> Parts;
	NewIP.ParseIntoArray(Parts, TEXT("."), true);
	if (Parts.Num() != 4)
		return false;

	//String to Number Parts
	for (int32 i = 0; i < 4; ++i)
	{
		Out[i] = FCString::Atoi(*Parts[i]);//Carefull with this part for errors
	}

	return true;
}
////-------------------------------------------------------------------------------------------------------------------------------------
////Rama's Create TCP Connection Listener
FSocket* ATCPSocket::CreateTCPConnectionListener(const FString& YourChosenSocketName, const FString& TheIP, const int32 ThePort, const int32 ReceiveBufferSize)
{
	uint8 IP4Nums[4];
	if (!FormatIP4ToNumber(TheIP, IP4Nums))
	{
		//VShow("Invalid IP! Expecting 4 parts separated by .");
		return false;
	}

	//Create Socket
	FIPv4Endpoint Endpoint(FIPv4Address(IP4Nums[0], IP4Nums[1], IP4Nums[2], IP4Nums[3]), ThePort);
	FSocket* ListenSocket = FTcpSocketBuilder(*YourChosenSocketName)
		.AsReusable()
		.BoundToEndpoint(Endpoint)
		.Listening(0);

	//Set Buffer Size TODO: maybe 1024
	int32 NewSize = 1024;
	ListenSocket->SetReceiveBufferSize(ReceiveBufferSize, NewSize);

	//Done!
	return ListenSocket;
}
void ATCPSocket::EndInput()
{
	GameEnded = true;
}
//
//
////Rama's TCP Connection Listener
void ATCPSocket::TCPConnectionListener()
{

	//~~~~~~~~~~~~~
	if (!ListenerSocket) return;
	//~~~~~~~~~~~~~
	//Remote address
	TSharedRef<FInternetAddr> RemoteAddress = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	bool Pending;

	// handle incoming connections
	ListenerSocket->HasPendingConnection(Pending);

	if (Pending)
	{
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		//Already have a Connection? destroy previous
		if (ConnectionSocket)
		{
			ConnectionSocket->Close();
			ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ConnectionSocket);
		}
		//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

		//New Connection receive!
		ConnectionSocket = ListenerSocket->Accept(*RemoteAddress, TEXT("TCP Received Socket Connection"));


		if (ConnectionSocket != NULL)
		{
			//Global cache of current Remote Address
			RemoteAddressForConnection = FIPv4Endpoint(RemoteAddress);

			//can thread this too
			UWorld* World = GetWorld();

			World->GetTimerManager().SetTimer(TCPSocketListenerTimerHandle, this, &ATCPSocket::TCPSocketListener, 0.3f, true);
		}
	}
}
//
//**//Rama's String From Binary Array
FString ATCPSocket::StringFromBinaryArray(TArray<uint8> BinaryArray)
{

	//Create a string from a byte array!
	const std::string cstr(reinterpret_cast<const char*>(BinaryArray.GetData()), BinaryArray.Num());

	return FString(cstr.c_str());

	//BinaryArray.Add(0); // Add 0 termination. Even if the string is already 0-terminated, it doesn't change the results.
	// Create a string from a byte array. The string is expected to be 0 terminated (i.e. a byte set to 0).
	// Use UTF8_TO_TCHAR if needed.
	// If you happen to know the data is UTF-16 (USC2) formatted, you do not need any conversion to begin with.
	// Otherwise you might have to write your own conversion algorithm to convert between multilingual UTF-16 planes.
	//return FString(ANSI_TO_TCHAR(reinterpret_cast<const char*>(BinaryArray.GetData())));
}
//
////Rama's TCP Socket Listener
void ATCPSocket::TCPSocketListener()
{
	//~~~~~~~~~~~~~
	if (!ConnectionSocket) return;
	//~~~~~~~~~~~~~


	//Binary Array!
	TArray<uint8> ReceivedData;

	uint32 Size;
	while (ConnectionSocket->HasPendingData(Size))
	{
		ReceivedData.Init(FMath::Min(Size, 65507u), Size);

		int32 Read = 0;
		ConnectionSocket->Recv(ReceivedData.GetData(), ReceivedData.Num(), Read);
	}
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	if (ReceivedData.Num() <= 0)
	{
		return;
	}
	//TCPSend("Message recived");
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//						Rama's String From Binary Array
	const FString ReceivedUE4String = StringFromBinaryArray(ReceivedData);
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	//recievedMessage(ReceivedUE4String);
	if (GameEnded == false) {//Maybe add mutex here, since both sockets are using this singleton
		InputService::getInstance(nullptr)->SendCommand(ReceivedUE4String, Player);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("As String Data ~> %s"), *ReceivedUE4String));
	}
	else {
		if (ReceivedUE4String.Equals("restart")) {
			UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
		}
	}
	//TCPSend("Message recived");
}
//
FString ATCPSocket::GetAlteredDTO(FString ToSend) {
	std::string ToSendLen = std::to_string(ToSend.Len());
	//number of zeroes in front - example  00001428 - 4 zeros
	int n_zero = (8 - ToSendLen.length());
	//add n times char '0' in front
	std::string numberOfCharacters = std::string(n_zero, '0');
	numberOfCharacters.append(ToSendLen);
	FString numberOfCharacterFStr(numberOfCharacters.c_str());

	return numberOfCharacterFStr + ToSend;
}

void ATCPSocket::TCPSend(FString ToSend) {
	//UE_LOG(LogTemp, Warning, TEXT("%s"), *ToSend);
	//amount of chars we are sending - without zeroes in front
	FString ToSendWithNumOfChars = GetAlteredDTO(ToSend);


	TCHAR* SerializedChar = ToSendWithNumOfChars.GetCharArray().GetData();
	int32 Size = FCString::Strlen(SerializedChar);
	int32 Sent = 0;
	std::string stringUTF8(TCHAR_TO_UTF8(SerializedChar));
	char* charsUFT8 = new char[stringUTF8.size()];
	std::copy(stringUTF8.begin(), stringUTF8.end(), charsUFT8);
	uint8* ResultChars = (uint8*)(charsUFT8);
	if (!ConnectionSocket->Send(ResultChars, Size, Sent)) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Error sending message")));
	}
}
