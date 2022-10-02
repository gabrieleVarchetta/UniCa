% Help:
%La funzione implementa il metodo di bisezione per il calcolo della radice
%approssimata di un'equazione nonlineare. In input prende la funzioine da
%calcolare, gli estremi dell'intervallo di partenza, una tolleranza tol e
%il massimo numero di iterazioni da eseguire. In output restituisce
%l'approssimazione della radice insieme al numero di iterazioni effettuate.

function [x,k] = bisec(fun, a, b, tol, kmax)

%calcolo della funzione nei due estremi
fa = fun(a);
fb = fun(b);

%se il segno è uguale, l'intervallo è sbagliato
if (fa*fb > 0)
    error('Intervallo sbagliato!')
end

% prima iterazione
k = 1;
c = (a+b)/2; % calcolo del punto medio dell'intervallo
fc = fun(c); % calcolo della funzione nel punto medio

%se la funzione calcolata nel punto medio si avvicina molto allo zero,
%posso restituire direttamente quel valore del punto medio
if (abs(fc) < 1e-10)
    x = c;
    return
end

flag = 1;

while (flag~=0)
    k = k+1; % incremento del contatore di iterazioni
    
    %dopo aver calcolato il punto medio, si costruisce il nuovo interballo.
    %se la funzione in a ha segno discorde rispetto alla funzione in c, il
    %nuovo intervallo diventa [a,c], altrimenti diventa [c,b]
    if (fa*fc < 0)
        b = c;
        fb = fc;
    else
        a = c;
        fa = fc;
    end
    
    % calcolo della successiva iterazione
    c = (a+b)/2;
    fc = fun(c);
    
    %il flag viene modificato in base a 3 criteri, che sono i 3 criteri di
    %arresto, ovvero distanza tra i due estremi troppo piccola, superamento
    %del numero massimo di iterazioni oppure il metodo è arrivato alla
    %soluzione (f(c) = 0)
    flag = (abs(b-a) > tol) && (k<kmax) && (abs(fc)>1e-10);
end

%se il massimo numero di iterazioni è stato superato, allora il metodo non
%converge
if (k>=kmax)
    warning('N. massimo di terazioni raggiunto')
    x = inf;
elseif (abs(fc)<=1e-10) % altrimenti, se la funzione calcolata in c è molto 
                        % vicina allo zero, si prende quel valore di c come
                        % radice
    x = c;
else
    x = (a+b)/2; %ultima approssimazione della radice
end


    
    
    


