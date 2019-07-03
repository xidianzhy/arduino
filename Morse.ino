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
  int i, t , temp = 0;
  int n = 0;  //对传入字符个数计数
  while (Serial.available() > 0) {
    temp = 1;  //判断是否有数据传入
    str += char(Serial.read());  //将传入的数据储存在字符串中
    delay(1000);  //延迟保证传入正常
    n++;
  }

  if (temp) {
    //查询Morse电码表并进行转换
    for (i = 0; i < n; i++)
    {

        //判断是否为小写字母，如果是则转义
        if (str[i] >= 97 && str[i] <= 122)
        {
          output += String(MORSE[int(str[i] - 97)]);
        }
        else output += String(MORSE[int(str[i] - 65)]);

      
    }
    Serial.print(output);  //串口传入
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
       if(output[j]==32)
       {
        delay(3000);
       }
       if(output[j]==13)
       {
        delay(3000);
        }
    }
    delay(3000);
  
}
