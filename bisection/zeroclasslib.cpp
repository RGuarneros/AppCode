#include <iostream>
using std::cout;

#include <vector>
using std::vector;

#include "zeroclasslib.hpp"

polynomial::polynomial(vector<double> c){
  if (c.at(0)==0){throw(29);}
  coefficients=c;
};

bool polynomial::is_odd() const{
  return coefficients.size()%2==0; 
};

double polynomial::evaluate_at(double x) const{
  double result=0;
  int size=coefficients.size()-1;
  for (int iter=0;iter<=size;iter++){
    result = (x*result) + coefficients.at(iter);
  }
  return result;
};

void find_initial_bounds
(const polynomial& po, double &left, double &right){
  if (!po.is_odd() || left>=right){throw(1);return;}
  while(po.evaluate_at(left)*po.evaluate_at(right)>0){
    left--;
    right++;
  }
  return;
}

void move_bounds_closer
(const polynomial& po,double& left,double& right){
  find_initial_bounds(po,left,right);
  double mid=(left+right)/2;
  if (po.evaluate_at(mid)<0){left=mid;}
  else {right=mid;}
  if (left>=right){throw(1);}
  return;
}


double find_zero( const polynomial& po,double prec){
  double left{10}, right{11},guess{0};
  while(std::abs(po.evaluate_at(guess))>prec){
    move_bounds_closer(po, left, right);
    guess=left;
  }
  return guess;

}

