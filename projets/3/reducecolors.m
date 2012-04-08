
function [newcolormap,ErrMin,PosMin,ValMin]=reducecolors(f,k)

  % calcule les niveaux qui minimisent l'erreur par programmation dynamique
  
  % f contient l'histogramme des valeurs (entre 1 et nmax)
  
    n=size(f,2);
    
    ErrMin=NaN*zeros(n,k); % ErrMin(i,j) est l'erreur de segmentation de
                       % f[1..i] en j niveaux
    PosMin=NaN*zeros(n,k); % PosMin(i,j) est la borne inf du dernier intervalle
                       % de la segmentation de f[1..i] en j niveaux
    ValMin=NaN*zeros(n,k); % ValMin(i,j) est le niveau associé au dernier
                           % intervalle de la segmentation de f[1..i] en j niveaux
    
    % initialisation
    
    for j=1:n
      [val,err]=reducecolorsone(f,1,j);
      ErrMin(j,1)=err;
      PosMin(j,1)=0;
      ValMin(j,1)=val;
    end
    
    % Boucle de remplissage de la table basée sur la récurrence:
    % ErrMin(n,k)=min_{j<n}\{ErrMin(j,k-1),ErrMinOne(f[j+1..n])\}
    
    for kp=2:k
      for np=kp:n
        minerr=Inf;
        for j=(kp-1):(np-1)
          [val,errone]=reducecolorsone(f,(j+1),np);
          currenterr=ErrMin(j,kp-1)+errone;
          if currenterr<minerr
            minerr=currenterr;
            minj=j;
            minval=val;
          end          
        end
        ErrMin(np,kp)=minerr;
        PosMin(np,kp)=minj;        
        ValMin(np,kp)=minval;
      end
    end
    
    % On retrouve la segmentation:
    
    newcolormap=zeros(size(f));
    
    pos=n;
    for kp=k:-1:1
      val=ValMin(pos,kp);
      jmin=PosMin(pos,kp);
      for j=pos:-1:(jmin+1)
        newcolormap(j)=val;
      end
      pos=jmin;
    end
    
    % check error
    error=f*(((1:n)-newcolormap).^2)'