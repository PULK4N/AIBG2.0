import socket.ClientSocket;

public class Start {
    public static void main(String[] args) {
        ClientSocket clientSocket = new ClientSocket();
        clientSocket.startConnection();
        clientSocket.setTeamName();
        clientSocket.receive();
        clientSocket.stopConnection();
    }
}
