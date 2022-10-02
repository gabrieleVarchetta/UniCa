% Help:
%La funzione implementa il metodo delle secanti per il calcolo della radice
%approssimata di un'equazione nonlineare. In input prende la funzione da
%calcolare, due punti x0 e x1, una tolleranza tol e il massimo numero di
%iterazioni da eseguire. In output restituisce la soluzione approssimata e
%il numero di iterazioni effettuato.

function [x, k] = secanti(fun, x0, x1, tau, nmax)

k = 0;

%se la funzione calcolata nel punto x0 si avvicina molto allo zero,
%posso restituire direttamente quel valore come radice
if abs(fun(x0)) < 1e-10
    x = x0;
    return 
end

flag=1;

while flag
    k = k+1; % incremento del contatore delle iterazioni

    %calcolo del coefficiente angolare m usando la formula
    %mk = [ f(xk) - f(xk-1) ] / ( xk - xk-1 )
    m = (fun(x1) - fun(x0)) / (x1-x0);
                                       
    %iterazione con secanti: xk+1 = xk - [f(xk) / mk]
    x = x1 - (fun(x1)/m); 
    
    %aggiornamento dei due punti per la successiva iterazione
    x0 = x1; 
    x1 = x;

    %il flag viene modificato in base a 3 criteri, che sono i 3 criteri di
    %arresto, ovvero distanza tra i due estremi troppo piccola, superamento
    %del numero massimo di iterazioni oppure il metodo è arrivato alla
    %soluzione (f(x) = 0)
    flag = ((abs(x-x0))> tau)&&(k<nmax)&&(fun(x)~=0);
end

%se il massimo numero di iterazioni è stato superato, allora il metodo non
%converge
if k >= nmax
    warning("Numero massimo iterazioni raggiunto")
end