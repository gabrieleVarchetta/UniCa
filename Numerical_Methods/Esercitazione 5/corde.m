% Help:
%La funzione implementa il metodo delle corde per il calcolo della radice
%approssimata di un'equazione nonlineare. In input prende la funzione da
%calcolare, il coefficiente angolare m (che sarà costante e sarà la
%derivata prima calcolata in x0), una tolleranza tol e il massimo numero di
%iterazioni che può eseguire. In output restituisce la radice approssimata
%insieme al numero di iterazioni effettuate.

function [x, k] = corde(fun, m, x0, tau, nmax)

k = 0;

%se la funzione calcolata nel punto x0 si avvicina molto allo zero,
%posso restituire direttamente quel valore come radice
if abs(fun(x0)) < 1e-10
    x = x0;
    return 
end

%inizializzazione di x
x = x0;

flag = 1;

while flag
    k = k+1; %incremento del contatore di iterazioni
    x0 = x; %imposto la x che verrà utilizzata nel calcolo successivo
    x = x0 - (fun(x0)/m); % iterazione con corde: xk = fun(xk) / m

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
