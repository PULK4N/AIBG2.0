// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Networking.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TCPSocket.generated.h"

class AGamePlayer;

UCLASS()
class AIBG20_API ATCPSocket : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATCPSocket();
	~ATCPSocket();

protected:
	// Called when the game starts or when spawned
	bool GameEnded = false;
	UPROPERTY(VisibleAnywhere)
	AGamePlayer* Player;
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	FSocket* ListenerSocket;
	FSocket* ConnectionSocket;
	FIPv4Endpoint RemoteAddressForConnection;


	FTimerHandle TCPSocketListenerTimerHandle;
	FTimerHandle TCPConnectionListenerTimerHandle;

	bool StartTCPReceiver(
		const FString& YourChosenSocketName,
		const FString& TheIP,
		const int32 ThePort
	);

	FSocket* CreateTCPConnectionListener(
		const FString& YourChosenSocketName,
		const FString& TheIP,
		const int32 ThePort,
		const int32 ReceiveBufferSize = 2 * 1024 * 1024
	);

	void EndInput();

	//Timer functions, could be threads
	void TCPConnectionListener(); 	//can thread this eventually
	void TCPSocketListener();		//can thread this eventually
	FString StringFromBinaryArray(TArray<uint8> BinaryArray);

	bool LaunchTCP(FString Port, AGamePlayer* player);

	void TCPSend(FString message);

	//Format String IP4 to number array
	bool FormatIP4ToNumber(const FString& TheIP, uint8(&Out)[4]);

};
