#include <bits/stdc++.h>
using namespace std;
class DiCho{
  private:
     double luongTien;
  public :
      friend istream & operator >> (istream &in, DiCho &);
      friend double getMoney(const DiCho &);

};
 double getMoney(const DiCho &a){return a.luongTien;}
   istream & operator >> (istream &in, DiCho &a)
   {   cout << "Vui long nhap luong tien di cho : ";
       in >> a.luongTien;
       return in;
   }
   double Total_1product(int soLuong, double giaThanh){

    return 1.0*soLuong*giaThanh;
    }

   void Input(double a[], double b[], int k)
   {
       for(int i =0; i < k ;i++){
            cout << "Hay nhap so luong " << i+1 <<": " ;
            cin >> a[i]; cout << endl;
         cout << "Hay nhap gia Thanh : ";
       cin >>b[i]; cout << endl;

       }

   }
   void Output(double a[], double b[] , int k)
   {   double tong = 0;
       for(int i = 0;  i < k ;i++)
       {
           cout << "So luong mua cua san pham thu " << i+1 <<": " << a[i]   <<"  ";
           cout << "Gia thanh san pham tren 1 don vi san pham " << ' ' << b[i] <<"  ";
           cout << "Thanh toan: " <<fixed << setprecision(0) << Total_1product(a[i],b[i]) << endl;
           tong += Total_1product(a[i], b[i]);
       }
       cout << "---------Total : " << fixed << setprecision(0) << tong << endl;
       cout << endl;
   }


  bool check(double luongTien,double a[], double b[] , int k){
      double tong =0 ;
    for(int i = 0 ; i < k ;i++ )
    {
        tong +=Total_1product(a[i],b[i]);

    }

   if(luongTien >= tong){
        cout << "Du tien " << endl;
        cout << "So tien con lai: " <<fixed << setprecision(0)  << luongTien - tong << " VND " << endl;
        return true;}
   return false;}
double check_Du_Tien(double luongTien, double a[], double b[], int k){
    cout << "So tien la khong du" << endl;
    int p ;
    cout << "Vui long chon phuong thuc" << endl;
    cout << "1.  Mua tat ca mat hang co gia thanh tren mot don vi san pham gia re nhat :" << endl <<
            "2.  Mua tat ca mat hang co tong gia tri (tren danh sach can mua) la re nhat :"  << endl;


   cin >>p;

   if(p == 1){
       cout << "Vui long chon gia re nhat tren 1 san pham " << endl;
      Input(a,b,k);
   }
   if(p == 2){
    cout << "Vui long bo bot san pham   " << endl;
    Output(a,b,k);
    Input(a,b,k);

   }
  if(!check(luongTien,a,b,k)){return check_Du_Tien(luongTien,a,b,k);}
  return  true;
}



int main()
{
DiCho x;
cin >> x;
double luongTien = getMoney(x);
cout << endl;
cout << "Vui long nhap so mat hang can mua : ";
int k ; cin >>k;


double a[k],b[k];
Input(a,b,k);
if(!check(luongTien,a,b,k)){check_Du_Tien(luongTien,a,b,k);
}

Output(a,b,k);






}
