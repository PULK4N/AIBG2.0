package socket;

import action.InputAction;
import dto.DTO;

import java.io.*;
import java.net.Socket;
import java.util.concurrent.TimeUnit;

public class ClientSocket {
    private Socket clientSocket;
    private PrintWriter out;
    private BufferedReader in;

    private DTO dto;
    private boolean exceptionOccured;

    public ClientSocket() {
        this.exceptionOccured = false;
    }

    public void startConnection() {
        try {
            clientSocket = this.selectPlayer();
            out = new PrintWriter(clientSocket.getOutputStream(), true);
            in = new BufferedReader(new InputStreamReader(clientSocket.getInputStream()));
        } catch (IOException e) {
            exceptionOccured = true;
            e.printStackTrace();
        }

        if(exceptionOccured){
            exceptionOccured = false;
            startConnection();
        }
    }

    public void setTeamName() {
        out.println(GameSettings.TEAM_NAME);
        dto = getDTOMessage();

        if(exceptionOccured){
            exceptionOccured = false;
            setTeamName();
        }
    }

    public void attemptReconnect() {
        try {
            TimeUnit.MILLISECONDS.sleep(1000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        startConnection();
        setTeamName();
    }

    public void sendMessage(String msg) {
        out.println(msg);
    }

    private void startPlaying(int game){
        int turn = 1;
        while(turn < GameSettings.RESTART_TURN + 1){
            if(turn != 1){
                dto = getDTOMessage();
            }

            if (GameSettings.RESTART && turn == GameSettings.RESTART_TURN) {
                if (game != GameSettings.AMOUNT_OF_GAMES - 1) {
                    if (GameSettings.PLAYER_NUM == 1) {
                        sendMessage("restart");
                    }
                    attemptReconnect();
                }
            } else {
                String botMsg = botInput(dto);
                sendMessage(botMsg);
            }


            turn++;
        }
    }

    private DTO getDTOMessage() {
        try{
            char[] msgCharArray = new char[8];
            in.read(msgCharArray, 0, 8);
            int number = Integer.parseInt(new String(msgCharArray));
            char[] jsonCharArray = new char[number];
            in.read(jsonCharArray, 0, number);
            String json = new String(jsonCharArray);
            if(DTO.from_json(json) == null){
                exceptionOccured = true;
            }
            return DTO.from_json(json);
        }catch (IOException e) {
            e.printStackTrace();
            exceptionOccured = true;
        }
        return null;
    }

    public void receive() {
        for (int game = 0; game < GameSettings.AMOUNT_OF_GAMES; game++) {
            startPlaying(game);
        }
    }

    public void stopConnection() {
        try {
            in.close();
            out.close();
            clientSocket.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Socket selectPlayer() throws IOException {
        if (GameSettings.PLAYER_NUM == 1)
            return new Socket(SocketSettings.SERVER, SocketSettings.PORT_PLAYER_1);
        else
            return new Socket(SocketSettings.SERVER, SocketSettings.PORT_PLAYER_2);
    }

    private String botInput(DTO dto) {
        InputAction inputAction = new InputAction('H', null);
        return inputAction.toJSON();
    }
}
