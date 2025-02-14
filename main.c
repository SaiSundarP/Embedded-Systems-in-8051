#include <reg51.h>
#include <stdio.h>
#define lcd_dat P3
sbit rs=P2^0;
sbit rw=P2^1;
sbit e=P2^2;

void delay(int t){
   int i,j;
   for( i=0;i<t;i++){
      for( j=0;j<1255;j++){;}
      }
    }
void lcd_cmd(unsigned char c){
   lcd_dat = c;
   rs=0;
   rw=0;
   e=1;
   delay(10);
   e=0;
}
void lcd_data(unsigned char a){
   lcd_dat = a;
   rs=1;
   rw=0;
   e=1;
   delay(10);
   e=0;
   }
   
void init()    
{
    lcd_cmd(0x38);  
    delay(10);
    lcd_cmd(0x0c);  //turn on display
    delay(10);
    lcd_cmd(0x01);  //clear screen
    delay(10);
    lcd_cmd(0x8f);  //First row second character
    delay(10);
}

void main(void)
 { 
   // Write your code here
      unsigned char setCursor[16]={0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f};
      unsigned char ch[40] ="Embedded Systems";int j=15;int pos=0x8f;
      
      
     while(1){ 
      int i=0;init();
      while(ch[i]!=0 ){
      lcd_data(ch[i++]);
      lcd_cmd(0x18);
      delay(5);
     
      }
      
    } 
      
         
 }
