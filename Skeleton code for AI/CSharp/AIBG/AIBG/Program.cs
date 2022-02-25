namespace AIBG
{
    class Program
    {
        static void Main(string[] args)
        {
            GetSocket clientSocket = new GetSocket();
            clientSocket.StartConnection();
            clientSocket.SetTeamName();
            clientSocket.Receive();
            clientSocket.StopConnection();
        }
    }
    
}
