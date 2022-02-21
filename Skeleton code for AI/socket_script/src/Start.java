import socket.ClientSocket;
import socket.GameSettings;
import socket.SocketSettings;

public class Start {
    public static void main(String[] args) {
        ClientSocket clientSocket = new ClientSocket(SocketSettings.SERVER, SocketSettings.PORT_PLAYER_1);
        clientSocket.startConnection();
        clientSocket.sendMessage(GameSettings.TEAM_NAME);
        clientSocket.receive();
        clientSocket.stopConnection();
    }
}
