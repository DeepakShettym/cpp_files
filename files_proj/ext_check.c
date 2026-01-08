#include<stdio.h>
#include<stdint.h>
#include<string.h>

int main(int argc , char *argv[]){
    if(argc != 2){
        printf("usage : %s <file> \n",argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1] , "rb");

    if(!fp){
        perror("fopen");
        return 1;
    }

    unsigned char buf[12] = {0};

    fread(buf , 1 , sizeof(buf) , fp);
    fclose(fp);

    if(buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff){
        printf("JPEG image (.jpg) \n");
    }else if(memcmp(buf , "RIFF" , 4) == 0 && memcmp(buf + 8 , "WAVE", 4) == 0){
        printf("WAV audio (.wav)\n");
    } else if(memcmp(buf, "\x89PNG" , 4) == 0){
        printf("PNG image (.png)\n");
    }else if(memcmp(buf , "PK\x03\x04" , 4) == 0){
        printf("ZIP file (.zip) \n");
    }else{
        printf("unknown ext \n");
    }


    return 0;
}


/*

(whisper-venv) deepak@deepak-ThinkPad-E14-Gen-6:~/deepak_git/cpp_files/files_proj$ hexdump -C img2.jpg| head  

00000000  ff d8 ff e0 00 10 4a 46  49 46 00 01 01 01 00 48  |......JFIF.....H|
00000010  00 48 00 00 ff e2 0c 58  49 43 43 5f 50 52 4f 46  |.H.....XICC_PROF|
00000020  49 4c 45 00 01 01 00 00  0c 48 4c 69 6e 6f 02 10  |ILE......HLino..|
00000030  00 00 6d 6e 74 72 52 47  42 20 58 59 5a 20 07 ce  |..mntrRGB XYZ ..|
00000040  00 02 00 09 00 06 00 31  00 00 61 63 73 70 4d 53  |.......1..acspMS|
00000050  46 54 00 00 00 00 49 45  43 20 73 52 47 42 00 00  |FT....IEC sRGB..|
00000060  00 00 00 00 00 00 00 00  00 00 00 00 f6 d6 00 01  |................|
00000070  00 00 00 00 d3 2d 48 50  20 20 00 00 00 00 00 00  |.....-HP  ......|
00000080  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|

| ff d8 ff | is compared with (buf[0] == 0xff && buf[1] == 0xd8 && buf[2] == 0xff) -> results :  printf("JPEG image (.jpg) \n");

*/