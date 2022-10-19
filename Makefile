run: all
	./SIG---Gym--Um-Sistema-de-Gesto-de-Academias

all:
	gcc -c -Wall ./biblioteca/clientes/clientes.c; 
	gcc -c -Wall ./biblioteca/fun_reutilizaveis/fun_reutilizaveis.c; 
	gcc -c -Wall ./biblioteca/funcionarios/funcionarios.c; 
	gcc -c -Wall ./biblioteca/informes/informes.c; 
	gcc -c -Wall ./biblioteca/mensalidades/mensalidades.c; 
	gcc -c -Wall ./biblioteca/menu_principal/menu_principal.c;
	gcc -c -Wall ./biblioteca/pagamentos/pagamentos.c; 
	gcc -c -Wall ./biblioteca/reg_acesso/reg_acesso.c;
	gcc -o main *.o;

clean:
	rm./*.o