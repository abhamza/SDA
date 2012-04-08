
function [val,err]=reducecolorsone(f,i,j)
  
  n=length(f);
  val=round((i:j)*f(i:j)'/sum(f(i:j)));
  err=f(i:j)*(((i:j)-ones(1,(j-i+1))*val).^2)';
