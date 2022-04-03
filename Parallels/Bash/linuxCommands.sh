shutdown -h now					# Desligar
reboot -r now					# Reiniciar ou CTRL ALT DEL com root
echo $PATH						# Caminhos dos comandos
ps								# Processos rodando
top								# Programas rodando
jobs							# Programas em background
fg 1							# Deixa o programa em foreground espeficando o número do jobs
bg 1							# Deixa o programa em background com o número do CTRL Z
kill -9 1						# Termina o processo com o sinal e número do ps
killall -9 top					# Termina o processo pelo o sinal e nome do ps
killall5 -9 					# Termina todos os processos
ls  							# Mostra os conteúdos daquele diretório
cd 								# Entra em determinado diretório espeficado
pwd								# Mostra o caminho do diretório atual onde você se encontra
mkdir /test 					# Cria um diretório com o nome e caminho especificado
rmdir 							# Remove o diretório vazio especificado seu caminho e nome
rm -r							# Remove arquivos ou diretórios com itens
cp -Rvi /origem/ /destino/		# Copia os arquivos e sub-diretórios da origem para o destino
mv -iv origem destino			# Move ou renomeia os arquivos contidos nos caminhos descritos
cat								# Mostra o conteúdo texto ou binário do caminho do arquivo especificado
tac								# Mostra o conteúdo final do arquivo
head -n 20 test.c 				# Mostra o conteúdo do arquivo limitado o número de linhas dito ou padrão
nl test.c						# Mostra o número de linhas e conteúdo de um arquivo
clear							# Limpa a tela ou CTRL L
date							# Mostra ou muda a hora atual
df -hT							# Mostra espaço livre e ocupado de cada partição
du -hc							# Mostra o espaço ocupado pelos arquivos no diretório atual 
ln -s /origem link				# Cria um link simbólico ou hard com -d do conteúdo
find . -name test				# Proucura no caminho dito arquivos com o filtro estabelecido
free -mts 1						# Mostra a utilização de RAM a cada segundo determinado
greep test test.c 				# Procura tal palavra no arquivo ou no input

