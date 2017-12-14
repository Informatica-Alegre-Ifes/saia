<?php
	// Obtém o valor enviado pelo leitor via HTTP Request (GET Method).
	$umidade = $_GET["umidade"];

	// Cria uma conexão com o SGDB MySQL, utilizando a API MySQLi.
	$conexao = new mysqli("127.0.0.1", "irrigacao", "ifes2017", "IRRIGACAO");

	// Verifica se ocorreram erros durante a criação da conexão.
	if (mysqli_connect_errno())
	{
		printf("Não foi possível conectar-se ao SGDB MySQL: %s\n", mysqli_connect_error());
		exit();
	}
	
	// Cria uma transação SQL.
	$transacao = $conexao->prepare("INSERT INTO UMIDADE (UMID_VL_UMIDADE, UMID_DT_UMIDADE) VALUES (?, NOW())");

	// Associa, no script de transação SQL, os valores armazenados em variáveis de acordo
	// com o seu tipo ('i' define que o valor armazenado na variávei é do tipo inteiro).
	$transacao->bind_param('i', $umidade);

	// Executa a transação SQL.
	$transacao->execute();

	// Fecha a conexão com o SGDB.
	$conexao->close();
?>