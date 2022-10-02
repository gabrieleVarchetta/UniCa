% Help:
%La funzione implementa il metodo di newton per il calcolo della radice
%approssimata di un'equazione nonlineare. In input prende la funzioine da
%calcolare, la sua derivata, un punto di partenza x0, una tolleranza tol e il massimo numero di 
%iterazioni da eseguire. In output restituisce l'approssimazione della 
%radice insieme al numero di iterazioni effettuate.

function [x,k] = newton(fun, fund, x0, tau, nmax)

k = 0;

%se la funzione calcolata in x0 ha un valore prossimo allo 0, allora si
%restituisce quel valore x0 come radice
if abs(fun(x0)) < 1e-10
    x = x0;
    return 
end

%se la derivata calcolata in x0 ha un valore prossimo allo 0, vuol dire che
%la retta tangente è parallela all'asse delle ascisse e dunque non si
%intersecheranno (non esiste una soluzione)
if abs(fund(x0)) < 1e-10
    error("Derivata nulla, cambia x0")
end

% inizializzazione di x
x = x0;

flag = 1;

while flag
    k = k+1; % incremento del contatore di iterazioni
    x0 = x; %imposto la x che verrà utilizzata nel calcolo successivo
    x = x0 - (fun(x0)/fund(x0)); % iterazione con newton: xk = fun(xk) / fund(xk)

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