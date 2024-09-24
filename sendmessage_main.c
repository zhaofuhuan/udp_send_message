//#inlcude <sys/socket.h>
//#include <getopt.h>
//#include <stdio.h>
//int main(int argc, char *argv[])
//{	
	
//	int ch;
//	int n;
//	while((ch=getopt(argc,argv,"lcdt"))!=-1)
//    {
//        switch(ch)
//        {
//        case 'l':
//        {
        
//        if (( n = sendto(servsockfd, str, length, 0, (struct sockaddr*)&cliaddr_tmp, sizeof(cliaddr_tmp))) < 0)
//          break;
//        }
//        case 'l':
//        {
//          break;
//        }
//		default:
//			break;
//     }

//    return 0;

//}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
 
int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    unsigned char buffer[1024];
    int n;
 
//    if (argc != 3) {
//        printf("usage: %s <server_ip> <port>\n", argv[0]);
//        return 1;
//    }
 
    // 创建socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
 
    // 定义服务器地址
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5025);
    inet_pton(AF_INET, "10.11.1.131", &server_addr.sin_addr);
	unsigned char  BBU_CFG_MSG_FREQ[24] = {0xC0,0x02,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x15,0x28,0xde,0xc0};
 	unsigned char  BBU_CFG_MSG_RFREQ[24] = {0xC0,0x02,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x15,0xc1,0x75,0x40};
	
	unsigned char  BBU_CFG_MSG_TXPOWER[24] = {0xC0,0x02,0x03,0x81,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x00,0x00,0x03,0xe8};
	
	unsigned char  BBU_CFG_MSG_DIVRECV[22] = {0xC0,0x02,0x02,0x03,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x02,
  							0x00,0x00};

							
	unsigned char  modify_BBU_CFG_MSG_FREQ[24] = {0xC0,0x02,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x15,0x2a,0xc7,0x08};
 	unsigned char  modify_BBU_CFG_MSG_RFREQ[24] = {0xC0,0x02,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x15,0xc3,0x5d,0x88};
	
	unsigned char  modify_BBU_CFG_MSG_TXPOWER[24] = {0xC0,0x02,0x03,0x81,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x00,0x00,0x03,0xe9};
	
	unsigned char  modify_BBU_CFG_MSG_DIVRECV[22] = {0xC0,0x02,0x02,0x03,0x00,0x00,0x00,0x00,0x00,0x01,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x02,
  							0x00,0x01};

	unsigned char  view_BBU_CFG_MSG_FREQ[24] = {0xC0,0x02,0x01,0x06,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x00,0x00,0x00,0x00};
 	unsigned char  view_BBU_CFG_MSG_RFREQ[24] = {0xC0,0x02,0x03,0x01,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x00,0x00,0x00,0x00};
	
	unsigned char  view_BBU_CFG_MSG_TXPOWER[24] = {0xC0,0x02,0x03,0x81,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x04,
  							0x00,0x00,0x00,0x00};
	
	unsigned char  view_BBU_CFG_MSG_DIVRECV[22] = {0xC0,0x02,0x02,0x03,0x00,0x00,0x00,0x00,0x00,0x02,0xff,0xff,0x01,0x0d,0x00,0x00,0x00,0x21,0x00,0x02,
  							0x00,0x00};

							
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
		buffer[strcspn(buffer, "\n")] = '\0';
        	// 发送数据到服务器
        if (strcmp(buffer, "c0020295") == 0)//"c0020106")
		{
			
			n = sendto(sock, BBU_CFG_MSG_FREQ, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
			if(n == 24)
			{
				printf("Enter message %lx:: len::%d\n",0xc0020106,sizeof(BBU_CFG_MSG_FREQ)/sizeof(char));
				printf("sendret: %d \n", n);
			}

        			// 接收服务器响应
//        			n = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
//        			if (n > 0) 
//					{
//            			buffer[n] = '\0';
//            			fputs(buffer, stdout);
//        			}
					
//        		}
//		else if (strcmp(buffer, "c0020301") == 0)//"c0020301")
//        		{
        			
        			n = sendto(sock, BBU_CFG_MSG_RFREQ, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
					if(n == 24)
					{
						printf("Enter message %lx:: len::%d\n",0xc0020301,sizeof(BBU_CFG_MSG_RFREQ)/sizeof(char));
						printf("sendret: %d \n", n);
					}
					
        			// 接收服务器响应
//        			n = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
//        			if (n > 0) 
//					{
//            			buffer[n] = '\0';
//            			fputs(buffer, stdout);
//        			}
					
//        		}
//		else if (strcmp(buffer, "c0020381") == 0)//"c0020381") 
//        		{
					
        			n = sendto(sock, BBU_CFG_MSG_TXPOWER, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
					if(n == 24)
        			{
						printf("Enter message %lx:: len::%d\n",0xc0020381,sizeof(BBU_CFG_MSG_TXPOWER)/sizeof(char));
						printf("sendret: %d \n", n);
					}
        			// 接收服务器响应
//        			n = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
//        			if (n > 0) 
//					{
//            			buffer[n] = '\0';
//            			fputs(buffer, stdout);
//        			}
					
//        		}
//		else if (strcmp(buffer, "c0020203") == 0)//"c0020203") 
//    	{
    			
    			n = sendto(sock, BBU_CFG_MSG_DIVRECV, 22, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 22)
				{
					printf("Enter message %lx:: len::%d\n",0xc0020203,sizeof(BBU_CFG_MSG_DIVRECV)/sizeof(char));
					printf("sendret: %d \n", n);
				}
    			// 接收服务器响应
    			//n = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
//    			if (n > 0) 
//				{
//        			buffer[n] = '\0';
//        			fputs(buffer, stdout);
//    			}	
//    	}
        }
		else if (strcmp(buffer, "c0020106") == 0)
			{
				n = sendto(sock, modify_BBU_CFG_MSG_FREQ, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 24)
				{
					printf("Enter message %lx:: len::%d\n",0xc0020106,sizeof(BBU_CFG_MSG_FREQ)/sizeof(char));
					printf("sendret: %d \n", n);
				}
			}
		else if (strcmp(buffer, "c0020301") == 0)
			{
				n = sendto(sock, modify_BBU_CFG_MSG_RFREQ, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 24)
				{
					printf("Enter message %lx:: len::%d\n",0xc0020301,sizeof(BBU_CFG_MSG_RFREQ)/sizeof(char));
					printf("sendret: %d \n", n);
				}
			}
		else if (strcmp(buffer, "c0020381") == 0)
			{
				n = sendto(sock, modify_BBU_CFG_MSG_TXPOWER, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 24)
    			{
					printf("Enter message %lx:: len::%d\n",sizeof(BBU_CFG_MSG_TXPOWER)/sizeof(char));
					printf("sendret: %d \n", n);
				}
			}
		else if (strcmp(buffer, "c0020203") == 0)
			{
				n = sendto(sock, modify_BBU_CFG_MSG_DIVRECV, 22, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 22)
				{
					printf("Enter message %lx:: len::%d\n",0xc0020203,sizeof(BBU_CFG_MSG_DIVRECV)/sizeof(char));
					printf("sendret: %d \n", n);
				}
			}
		else if (strcmp(buffer, "vc0020106") == 0)
			{
				n = sendto(sock, view_BBU_CFG_MSG_FREQ, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 24)
				{
					printf("Enter message %lx:: len::%d\n",0xc0020106,sizeof(BBU_CFG_MSG_FREQ)/sizeof(char));
					printf("sendret: %d \n", n);
				}
			}
		else if (strcmp(buffer, "vc0020301") == 0)
			{
				n = sendto(sock, view_BBU_CFG_MSG_RFREQ, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 24)
				{
					printf("Enter message %lx:: len::%d\n",0xc0020301,sizeof(BBU_CFG_MSG_RFREQ)/sizeof(char));
					printf("sendret: %d \n", n);
				}
			}
		else if (strcmp(buffer, "vc0020381") == 0)
			{
				n = sendto(sock, view_BBU_CFG_MSG_TXPOWER, 24, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 24)
    			{
					printf("Enter message %lx:: len::%d\n",sizeof(BBU_CFG_MSG_TXPOWER)/sizeof(char));
					printf("sendret: %d \n", n);
				}
			}
		else if (strcmp(buffer, "vc0020203") == 0)
			{
				n = sendto(sock, view_BBU_CFG_MSG_DIVRECV, 22, 0, (struct sockaddr*)&server_addr, sizeof(server_addr));
				if(n == 22)
				{
					printf("Enter message %lx:: len::%d\n",0xc0020203,sizeof(BBU_CFG_MSG_DIVRECV)/sizeof(char));
					printf("sendret: %d \n", n);
				}
			}
	}
	close(sock);
    return 0;
}

