#include "Interface.h"

Interface::Interface() {

}

void Interface::cadastrar_cliente(Banco& b) {

	string cpf, nome, endereco, fone;

	cin.ignore();
	cout << "\n\n\n\tCADASTRAR CLIENTE\n" << endl;
	cout << "\t Digite o nome:";
	getline(cin, nome);
	cout << "\t Digite o cpf:";
	getline(cin, cpf);
	cout << "\t Digite o endereco:";
	getline(cin, endereco);
	cout << "\t Digite o fone:";
	getline(cin, fone);

	if (!b.checkCliente(cpf)) {

		b.inserirCliente(Banco::Cliente(nome, cpf, endereco, fone));
		cout << "\n\t Operacao realizada com sucesso ";
	}

	else {

		cout << "\n\t Cliente ja existente ";
	}

	getch();
}

void Interface::criar_conta(Banco& b) {

	string cpf;

	cin.ignore();
	cout << "\n\n\n\tCRIAR CONTA\n" << endl;
	cout << "\t Digite o cpf do cliente:";
	cin >> cpf;

	if (b.checkCliente(cpf)) {

		if (!b.checkConta(cpf)) {

			b.criarConta(*(b.cliente(b.findCliente(cpf))));
			cout << "\n\t Operacao realizada com sucesso! ";
		}

		else
			cout << "\n\t Cliente ja possui conta! ";
			
	}

	else
		cout << "\n\t Cliente inexistente! ";

	getch();
}

void Interface::excluir_cliente(Banco& b) {

	string cpf;

	cin.ignore();
	cout << "\n\n\n\tEXCLUIR CLIENTE\n" << endl;
	cout << "\t Digite o cpf do cliente:";
	cin >> cpf;

	if (b.checkCliente(cpf)) {

		if (!b.checkConta(cpf)) {

			b.excluirCliente(cpf);
			cout << "\n\t Operacao realizada com sucesso! ";
		}

		else
			cout << "\n\t Cliente possui conta! ";
	}

	else
		cout << "\n\t Cliente inexistente! ";
	
	getch();
}

void Interface::excluir_conta(Banco& b) {

	int numeroconta;

	cin.ignore();
	cout << "\n\n\n\tCRIAR CONTA\n" << endl;
	cout << "\t Digite o numero da conta: ";
	cin >> numeroconta;

	if (b.checkConta(numeroconta)) {

		b.excluirConta(numeroconta);
		cout << "\n\t Operacao realizada com sucesso! ";
	}

	else
		cout << "\n\t Conta inexistente! ";

	getch();
}

void Interface::deposito(Banco& b) {

	int numeroconta;
	double valor;

	cout << "\n\n\n\tDEPOSITO\n" << endl;
	cout << "\n\t Insira o numero da conta: ";
	cin >> numeroconta;
	cout << "\t Insira o valor a ser depositado: ";
	cin >> valor;

	if (b.checkConta(numeroconta)) {

		b.deposito(numeroconta, valor);
		cout << "\n\t Operacao realizada com sucesso! ";
	}

	else
		cout << "\n\t Conta inexistente! ";
	
	getch();
}

void Interface::saque(Banco& b) {

	int numeroconta;
	double valor;
	vector<Banco::Conta> c = b.contas();
	
	cin.ignore();
	cout << "\n\n\n\tSAQUE\n" << endl;
	cout << "\n\t Insira o numero da conta: ";
	cin >> numeroconta;
	cout << "\t Insira o valor a ser sacado: ";
	cin >> valor;
	
	if (b.checkConta(numeroconta)) {

		if (b.saque(numeroconta, valor)) {

			cout << "\n\t Operacao realizada com sucesso! ";
		}

		else
			cout << "\n\t Saldo insuficiente! ";
			
	}

	else
		cout << "\n\t Conta inexistente! ";

	getch();
}

void Interface::transferencia(Banco& b) {

	int numeroconta1, numeroconta2;
	double valor;
	vector<Banco::Conta> c = b.contas();

	cin.ignore();
	cout << "\n\n\n\tTRANSFERENCIA\n" << endl;
	cout << "\n\t Insira o numero da conta de origem: ";
	cin >> numeroconta1;
	cout << "\t Insira o numero da conta de destino: ";
	cin >> numeroconta2;
	cout << "\t Insira valor: ";
	cin >> valor;

	if (b.checkConta(numeroconta1)) {

		if (b.checkConta(numeroconta2)) {

			if (b.transferencia(numeroconta1, numeroconta2, valor)) {

				cout << "\n\t Operacao realizada com sucesso! ";
			}

			else
				cout << "\n\t Saldo induficiente! ";
		}

		else
			cout << "\n\t Conta de destino inexistente! ";
	}

	else 
		cout << "\n\t Conta de origem inexistente! ";

	getch();
}

void Interface::tarifa(Banco& b) {
	
	cin.ignore();
	cout << "\n\n\n\tTARIFA\n" << endl;
	cout << "\n\t Operacao realizada com sucesso ";
	b.tarifa();

	getch();
}

void Interface::CPMF(Banco& b) {

	cin.ignore();
	cout << "\n\n\n\tCMPF\n" << endl;
	cout << "\n\t Operacao realizada com sucesso ";
	b.CPMF();

	getch();
}

void Interface::saldo(Banco& b) {

	int conta;

	cin.ignore();
	cout << "\n\n\n\tSALDO\n" << endl;
	cout << "\n\t Insira numero da conta: ";
	cin >> conta;	

	if (b.checkConta(conta)) {

		cout << "\n\t R$" << fixed << setprecision(2) << b.saldo(conta);
	}

	else
		cout << "\n\t Conta inexistente! ";
	
	getch();
}

void Interface::extrato_mes(Banco& b) {

	Data x;
	int numeroconta;

	vector<Banco::Conta> contas;
	vector<Banco::Conta::Movimentacao> ext;

	cin.ignore();
	cout << "\n\n\n\tEXTRATO\n" << endl;
	cout << "\n\t Insira o numero da conta: ";
	cin >> numeroconta;
	contas = b.contas();

	if (b.checkConta(numeroconta)) {

		ext = b.extrato(numeroconta);

		for (Banco::Conta::Movimentacao j : ext)
			cout << "\n\t " << "R$" << fixed << setprecision(2) << j.Get_Valor() << " " << j.Get_Debito_Credito() << " " << j.Get_Descricao();		

		cout << "\n\t ===================================================================";
		cout << "\n\t Saldo: R$" << fixed << setprecision(2) << b.saldo(numeroconta);
	}

	else
		cout << "\n\t Conta inexistente! ";

	getch();
}


void Interface::extrato_data_inicial(Banco& b) {

	int dia, mes, ano, conta;

	vector<Banco::Conta> contas;
	vector<Banco::Conta::Movimentacao> ext;	

	cin.ignore();
	cout << "\n\n\n\tEXTRATO\n" << endl;
	cout << "\t Insira dia, mes e ano: ";
	cin >> dia >> mes >> ano;

	Data inicio = criarData(dia, mes, ano);

	cout << "\t Insira o numero da conta: ";
	cin >> conta;

	contas = b.contas();

	if (b.checkConta(conta)) {

		ext = b.extrato(conta, inicio);

		for (Banco::Conta::Movimentacao j : ext)
			cout << "\n\t " << "R$" << fixed << setprecision(2) << j.Get_Valor() << " " << j.Get_Debito_Credito() << " " << j.Get_Descricao();

		cout << "\n\t ===================================================================";
		cout << "\n\t Saldo: R$" << fixed << setprecision(2) << b.saldo(conta);
	}

	else
		cout << "\n\t Conta inexistente! ";


	getch();
}

void Interface::extrato_data_inicial_final(Banco& b) {

	int diaI, mesI, anoI, diaF, mesF, anoF, conta;

	vector<Banco::Conta> contas;
	vector<Banco::Conta::Movimentacao> ext;

	cin.ignore();
	cout << "\n\n\n\tEXTRATO\n" << endl;
	cout << "\t Insira o dia, mes e ano da data inicial: ";
	cin >> diaI;
	cin >> mesI;
	cin >> anoI;
	cout << "\t Insira o dia, mes e ano da data final: ";
	cin >> diaF;
	cin >> mesF;
	cin >> anoF;

	Data inicio = criarData(diaI, mesI, anoI);
	Data fim = criarData(diaF, mesF, anoF);

	cout << "\t Insira o numero da conta: ";
	cin >> conta;

	contas = b.contas();

	if (b.checkConta(conta)) {

		ext = b.extrato(conta, inicio, fim);

		for (Banco::Conta::Movimentacao j : ext)
			cout << "\n\t " << "R$" << fixed << setprecision(2) << j.Get_Valor() << " " << j.Get_Debito_Credito() << " " << j.Get_Descricao();

		cout << "\n\t ===================================================================";
		cout << "\n\t Saldo: R$" << fixed << setprecision(2) << b.saldo(conta);
	}

	else
		cout << "\n\t Conta inexistente! ";

	getch();
}

void Interface::listar_clientes(Banco& b) {

	vector<Banco::Cliente> clientes;
	clientes = b.clientes();

	cout << "\n\n\n\tCLIENTES\n" << endl;

	for (Banco::Cliente i : clientes) {

		cout << "\n\t Nome: " << i.Get_nome();
		cout << "\n\t CPF: " << i.Get_Cpf_cnpj();
		cout << "\n\t Endereco: " << i.Get_Fone();
		cout << "\n\t Telefone: " << i.Get_Endereco();
		cout << "\n\t ===================================================================\n";
	}

	getch();
}

void Interface::listar_contas(Banco& b) {

	vector<Banco::Conta> contas;
	contas = b.contas();

	cout << "\n\n\n\tCONTAS\n" << endl;

	for (Banco::Conta i : contas) {

		cout << "\n\t Numero da conta: " << i.Get_Numero_conta();
		cout << "\n\t CPF do Cliente: " << i.Get_cliente().Get_Cpf_cnpj();
		cout << "\n\t Saldo: " << fixed << setprecision(2) << "R$" << i.Get_saldo();
		cout << "\n\t ===================================================================\n";
	}

	getch();
}

void Interface::menu(Banco& b) {

	int escolha;

	do {

		system("cls");

		cout << "\n\n\n\tMENU " << endl;
		cout << "\n\t 1.Cadastrar Novo Cliente ";
		cout << "\n\t 2.Criar nova conta ";
		cout << "\n\t 3.Excluir Cliente ";
		cout << "\n\t 4.Excluir Conta ";
		cout << "\n\t 5.Efetuar Deposito ";
		cout << "\n\t 6.Efetuar Saque ";
		cout << "\n\t 7.Efetuar Transferencia entre Contas ";
		cout << "\n\t 8.Cobrar Tarifa ";
		cout << "\n\t 9.Cobrar CPMF ";
		cout << "\n\t 10.Obter Saldo ";
		cout << "\n\t 11.Obter Extrato ";
		cout << "\n\t 12.Listar Clientes ";
		cout << "\n\t 13.Listar Contas";
		cout << "\n\t 14.Sair" << endl;
		cout << "\n\t Insira opcao: ";
		cin >> escolha;

		switch (escolha) {

			case 1: {
						
				system("cls");
				cadastrar_cliente(b);
				break;
			}

			case 2: {
						
				system("cls");
				criar_conta(b);
				break;
			}

			case 3: {
						
				system("cls");
				excluir_cliente(b);
				break;
			}

			case 4: {
						
				system("cls");
				excluir_conta(b);
				break;
			}

			case 5: {
						
				system("cls");
				deposito(b);
				break;
			}

			case 6: {
						
				system("cls");
				saque(b);
				break;
			}

			case 7: {
						
				system("cls");
				transferencia(b);
				break;
			}

			case 8: {
						
				system("cls");
				tarifa(b);
				break;
			}

			case 9: {
						
				system("cls");
				CPMF(b);
				break;
			}

			case 10: {
						
				system("cls");
				saldo(b);
				break;
			}

			case 11: {
						
				system("cls");
				int escolha2;
				cout << "\n\n\n\tEXTRATO " << endl;
				cout << "\n\n\t 1.Extrato corrente ";
				cout << "\n\t 2.Extrado com data inicial ";
				cout << "\n\t 3.Extrado em um periodo de tempo ";
				cout << "\n\n\t Insira opcao: ";
				cin >> escolha2;
						
				switch (escolha2) {
				case 1: {
							
					system("cls");
					extrato_mes(b);
					break;
				}

				case 2: {
							
					system("cls");
					extrato_data_inicial(b);
					break;
						}

				case 3: {
							
					system("cls");
					extrato_data_inicial_final(b);
					break;
				}
				}

				break;
			}

			case 12: {
						
				system("cls");
				listar_clientes(b);
				break;
			}

			case 13: {
						
				system("cls");
				listar_contas(b);
				break;
			}

			case 14: {

				break;
			}
		}

	} while (escolha != 14);
}