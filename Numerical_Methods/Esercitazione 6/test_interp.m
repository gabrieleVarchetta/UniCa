% Help:
%Lo script va ad eseguire una serie di test con le due forme di
%interpolazione, in base canonica e in base di Lagrange, scegliendo le
%ascisse di interpolazione in due modi diversi, punti equispazati o zeri
%del polinomio di Chebychev.

%salvataggio delle due funzioni da interpolare in un array
fun_arr = {@(x) 1./(1 + 25.*x.^2); @(x) sin(2.*x.*pi)};

%numero di ascisse di interpolazione
n = 10;

%numero di ascisse per il grafico
m = 200;

choice = input("Inserire 1 se si vogliono usare i punti equispaziati, 2 se si vogliono usare gli zeri di Chebychev: ");

%il seguente switch permette la scelta tra i due modi di scegliere i punti
%di interpolazione
switch choice
    case 1
        %ciclo for per creare i grafici con i due metodi per entrambe le
        %funzioni
        for i = 1:2 
            %creazione di n punti nell'intervallo [-3.14, 3.14]
            x = linspace(-pi, pi, n)'; 

            %calcolo della funzione corrente nel punto x
            y = fun_arr{i}(x); 

            %creazione di m punti che vanno da x(1) a x(n)
            xx = linspace(x(1),x(n), m)';

            %calcolo del polinomio interpolante in base canonica
            yy = canint(x, y, xx);
            pause

            %calcolo del polinomio interpolante nella base di Lagrange
            yy = lagrint(x, y, xx);
            pause
        end

    case 2
        %creazione del polinomio di Chebychev
        chebFun = @(k) cos(((2*k+1)*pi)./(2*n+2));
        k = [0:1:n]'; %vettore di punti che vanno da 0 a n
        x = chebFun(k); % questo è il polinomio effettivo
        
        %ciclo for per creare i grafici con i due metodi per entrambe le
        %funzioni
        for i = 1:2 
            y = fun_arr{i}(x); %calcolo della funzione corrente in x (Chebychev)

            %creazione di m punti che vanno da x(1) a x(n)
            xx = linspace(x(1),x(n), m)';

            %calcolo del polinomio interpolante in base canonica
            yy = canint(x, y, xx);
            pause

            %calcolo del polinomio interpolante nella base di Lagrange
            yy = lagrint(x, y, xx); 
            pause
        end
       
    otherwise
        disp("La scelta effettuata non esiste");
end




