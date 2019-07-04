#include <Morse.h>
#define SIZE 26
//定义摩尔斯电码表
String MORSE[SIZE] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",  //A to I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",//J to R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."        //S to Z 
};
Morse morse(13);

void setup() {
  Serial.begin(9600);//设置通信波特率

}

void loop() {
  String str = "";    //储存串口读到的字符串
  String output = "";  //转义后字符串
  int i, t , q = 0;
  int n = 0;  //传入字符个数
  while (Serial.available() > 0) {
    q = 1;  //判断是否有数据传入
    str += char(Serial.read());  //将传入的数据储存在字符串中
    delay(1000);  //延迟1s
    n++;
  }

  if (q) {
    //查询Morse表进行转换
    for (i = 0; i < n; i++)
    {

        //判断是否为小写字母，如果是则转义
        if (str[i] >= 97 && str[i] <= 122)
        {
          output += String(MORSE[int(str[i] - 97)]);
        }
        else output += String(MORSE[int(str[i] - 65)]);
    }
    Serial.print(output);  //打印在串口监视器
  }
    for(int j=0;j<output.length()-1;j++)
    {
        if(output[j]==46)
        {
         morse.dot();
       }
        if(output[j]==45)
        {
         morse.dash();
       }
       if(output[j]==32)//如果空格，延迟3s
       {
        delay(3000);
       }
       if(output[j]==13)//如果回车，延迟3s
       {
        delay(3000);
        }
    }
    delay(3000);
  
}
