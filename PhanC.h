
#include <bits/stdc++.h>
using namespace std;
struct Debt{
   double tientraNo,khoanNo,tienLai;
   Debt(){}
  Debt( double _tientraNO,double _khoanNo){
      tientraNo = _tientraNO;
      khoanNo= _khoanNo;}
   void soDuNo(){
    tienLai = 0.02 * khoanNo;
    khoanNo= khoanNo - tientraNo;

 }




};
//   void tienNoTra1nam(double no){
//   for(int i = 0; i < 12 ;i++){no = 1.02 * no;}
//  }
