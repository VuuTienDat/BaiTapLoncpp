#include "PhanC.h"
#include "PhanD.h"
int main(){
    string Thang[]={"","Thang 09/2016","Thang 10/2016","Thang 11/2016",
    "Thang 12/2016","Thang 01/2017","Thang 02/2017","Thang 03/2017",
    "Thang 04/2017","Thang 05/2017","Thang 06/2017","Thang 07/2017",
    "Thang 08/2017"};

    double gioLam[]={0,155,145,125,135,100,100,145,135,100,155,170,180};
    Debt y;
    y.khoanNo = 10000000;

    for(int i = 1 ; i <= 12 ; i++)
    {
      NhanLuong x(gioLam[i]);
     x.Inraluong();
     x.LuongSauThue();

     double thunhap = x.luongThue + 1500000;
      cout <<fixed << setprecision(0) <<"Thu nhap "<< Thang[i] <<" "  <<  thunhap << "   ";
      y.tientraNo = thunhap-2000000 ;

    y.soDuNo();
    if(y.khoanNo <=0){cout << "Het No: "  << endl;
    if(abs(y.khoanNo ) > y.tienLai ){
        double tienNhanLai = abs(y.khoanNo)- y.tienLai ;
        cout  << "So tien nhan lai " << fixed << setprecision(0) << tienNhanLai <<" VND " << endl;
    }
    else {
        double tienDongThem = -(abs(y.khoanNo)- y.tienLai);
        cout  << "So tien nhan lai " << fixed << setprecision(0) << tienDongThem <<" VND "<< endl;
    }
    break;

    }

    else cout <<"Khoan No "<< y.khoanNo << "    Tien lai  " << y.tienLai << endl;
    }
}


