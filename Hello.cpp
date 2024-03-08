#include <bits/stdc++.h>
using namespace std;
struct NhanLuong{
     double gio,luong=0,thue=0,luongThue;


  NhanLuong(double hour){

  gio= hour;
  }
 double Inraluong(){
  if(gio > 200){luong += 3000000 +(gio-200)*25000; }
 else if(gio > 150 ){luong += 2000000+(gio -150)*20000;}
 else if(gio > 100){luong += 1200000 +(gio -100)*16000; }
 else {luong += gio * 12000;}
 return luong;}
 double LuongSauThue(){

 luong = 0.91*luong;
 if(luong >= 2000000){thue += 125000 +(luong-2000000)*0.2; }
 else if (luong >= 1500000){thue += 50000 +(luong -1500000)*0.15; }
 else if(luong > 1000000){thue += 0.1 *(luong -1000000);}
  else {thue =0;}
 cout << thue << endl;
 luongThue= luong/0.91 - thue;

  return luongThue;
 }


 };
 int main(){
  NhanLuong x(167);

 cout <<fixed <<setprecision(2) << x.Inraluong()  << endl;
  cout << fixed << setprecision(2)<< x.LuongSauThue()<< endl;

 cout <<fixed << setprecision(2)<< x.thue << endl;
 }
