run: all
	

all:
	gcc -c -Wall bibliotecas/clientes/clientes.c; 
	gcc -c -Wall bibliotecas/fun_reutilizaveis/fun_reutilizaveis.c; 
	gcc -c -Wall bibliotecas/funcionarios/funcionarios.c; 
	gcc -c -Wall bibliotecas/informes/informes.c; 
	gcc -c -Wall bibliotecas/mensalidades/mensalidades.c; 
	gcc -c -Wall bibliotecas/menu_principal/menu_principal.c;
	gcc -c -Wall bibliotecas/pagamentos/pagamentos.c; 
	gcc -c -Wall bibliotecas/reg_acesso/reg_acesso.c;
	gcc -c -Wall main.c
	gcc -o main *.o;

clean:
	rm./*.o