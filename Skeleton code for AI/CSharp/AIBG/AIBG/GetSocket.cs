using System;
using System.Text;
using System.Net;
using System.Net.Sockets;
using System.Collections.Generic;
using System.Threading;

namespace AIBG
{
    public class GetSocket
    {
        public Socket Client { get; set; }
        public string Address { get; set; }
        public DTO dto { get; set; }
        private bool ExceptionOccured { get; set; }

        public GetSocket()
        {
            ExceptionOccured = false;
        }
        public static Socket ConnectSocket(string server, int port)
        {
            Socket s = null;

            // Get host related information.
            IPHostEntry hostEntry = Dns.GetHostEntry(server);

            // Loop through the AddressList to obtain the supported AddressFamily. This is to avoid
            // an exception that occurs when the host IP Address is not compatible with the address family
            // (typical in the IPv6 case).
            foreach (IPAddress address in hostEntry.AddressList)
            {
                IPEndPoint ipe = new IPEndPoint(address, port);
                Socket tempSocket =
                    new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
                try
                {
                    tempSocket.Connect(ipe);
                }
                catch(Exception e)
                {
                    Console.WriteLine(e);
                }

                if (tempSocket.Connected)
                {
                    s = tempSocket;
                    break;
                }
                else
                {
                    continue;
                }
            }
            return s;
        }

        public void Send(string message)
        {
            byte[] bytesSent = Encoding.ASCII.GetBytes(message);
            Client.Send(bytesSent);
        }

        public void Receive()
        {
            for (int game = 0; game < Settings.AMOUNT_OF_GAMES; game++)
                StartPlaying(game);
        }

        private void StartPlaying(int game)
        {
            string botMessage = BotInput(dto);
            Send(botMessage);
            int turn = 2;
            while (turn < Settings.RESTART_TURN + 1)
            {
                if(Settings.PLAYER_NUM != 2 || turn != Settings.RESTART_TURN)
                {
                    dto = GetDTOMessage();
                }

                bool isLastGame = game == Settings.AMOUNT_OF_GAMES - 1;
                if(Settings.RESTART && turn == Settings.RESTART_TURN && isLastGame == false)
                {
                    if(game != (Settings.AMOUNT_OF_GAMES - 1))
                    {
                        if (Settings.PLAYER_NUM == 1)
                            Send("restart");
                        AttemptReconnect();
                    }
                }
                else
                {
                    Send(BotInput(dto));
                }
                turn++;
            }
        }

        public void AttemptReconnect()
        {
            try
            {
                if (Settings.PLAYER_NUM == 1)
                    Thread.Sleep(1000);
                else
                    Thread.Sleep(2000);
            }
            catch (Exception e)
            {
                Console.WriteLine(e);
            }
            StartConnection();
            SetTeamName();
        }

        public void SetTeamName()
        {
            Send(Settings.TEAM_NAME);
            dto = GetDTOMessage();
            if(ExceptionOccured)
            {
                ExceptionOccured = false;
                SetTeamName();
            }
        }

        public void StartConnection()
        {
            try
            {
                Client = SelectPlayer();
            } 
            catch(Exception e)
            {
                ExceptionOccured = true;
                Console.WriteLine(e);
            }

            if(ExceptionOccured)
            {
                ExceptionOccured = false;
                StartConnection();
            }
        }

        public void StopConnection()
        {
            try
            {
                Client.Close();
            }
            catch(Exception e)
            {
                Console.WriteLine(e);
            }
        }

        private Socket SelectPlayer()
        {
            Thread.Sleep(1000);
            try
            {
                IPHostEntry hostEntry = Dns.GetHostEntry(Settings.SERVER);
                IPAddress address = hostEntry.AddressList[1];
                IPEndPoint ipe;
                if (Settings.PLAYER_NUM == 1)
                    ipe = new IPEndPoint(address, Settings.PORT_PLAYER_1);
                else
                    ipe = new IPEndPoint(address, Settings.PORT_PLAYER_2);
                Socket s = new Socket(ipe.AddressFamily, SocketType.Stream, ProtocolType.Tcp);
                s.Connect(ipe);
                if (s.Connected == false)
                {
                    Console.WriteLine("nece da radi");
                    return SelectPlayer();
                }
                return s;
            }
            catch
            {
                return SelectPlayer();
            }
        }

        private DTO GetDTOMessage()
        {
            try
            {
                byte[] integer = new byte[8];
                Client.Receive(integer);
                string s = Encoding.UTF8.GetString(integer);
                int number = int.Parse(s);

                byte[] jsonBytes = new byte[number];
                Client.Receive(jsonBytes);
                string json = Encoding.UTF8.GetString(jsonBytes);

                DTO fromJSON = DTO.GetDTOFromJSON(json);
                if (fromJSON == null)
                    ExceptionOccured = true;
                return fromJSON;
            }
            catch(Exception e)
            {
                Console.WriteLine(e);
                ExceptionOccured = true;
            }
            return null;
        }

        private string BotInput(DTO dto)
        {
            List<Action> actions = new List<Action>();
            actions.Add(new Action(1, 1, 0, 0));
            InputAction inputAction = new InputAction("L", actions);
            return inputAction.ToJSON();
        }

        // This method requests the home page content for the specified server.
        public static string SocketSendReceive(string server, int port)
        {
            string request = "GET / HTTP/1.1\r\nHost: " + server +
                "\r\nConnection: Close\r\n\r\n";
            byte[] bytesSent = Encoding.ASCII.GetBytes(request);
            byte[] bytesReceived = new byte[256];
            string page = "";

            // Create a socket connection with the specified server and port.
            using (Socket s = ConnectSocket(server, port))
            {
                if (s == null)
                    return ("Connection failed");

                // Send request to the server.
                s.Send(bytesSent, bytesSent.Length, 0);

                // Receive the server home page content.
                int bytes = 0;
                page = "Default HTML page on " + server + ":\r\n";

                // The following will block until the page is transmitted.
                do
                {
                    Console.WriteLine("I was here");
                    bytes = s.Receive(bytesReceived, bytesReceived.Length, 0);
                    page += Encoding.ASCII.GetString(bytesReceived, 0, bytes);
                }
                while (bytes > 0);
            }
            return page;
        }
    }
}