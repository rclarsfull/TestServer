package com.company;

import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner eingabe=new Scanner(System.in);
        EchoServer test=new EchoServer(5000);
        byte [] data=new byte[255];


        System.out.print("Server IP: ");
        String ip=eingabe.next();
        System.out.print("Port: ");
        int port=eingabe.nextInt();
        String dataStr="";

        boolean run=true;

        while (run) {
            if (dataStr.equals("stop")){
                run=false;
                test.stopSocket();
                break;
            }
            dataStr=eingabe.next();
            data=dataStr.getBytes();

            try {
                test.sendUdpPacket(InetAddress.getByName("192.168.178.148"),5000,data);
            } catch (UnknownHostException e) {
                e.printStackTrace();
                System.out.println("Fehler");
                test.stopSocket();
            }

        }

    }
}
