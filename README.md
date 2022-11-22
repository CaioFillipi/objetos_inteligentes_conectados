# Objetos Intelegentes Conectados 
Repositório contendo o projeto Arduino.

O projeto tem como intuito o desenvolvimento de um alimentador automático para peixes utilizando Arduino e o protocolo MQTT para comunicação web. O projeto possui dois tipos de acionamento, um automático que é realizado a cada 8 horas e um comandado que pode ser acessado via interface web e realizar o acionamento do motor por algum dispositivo via web. O repositório possui uma imagem com o esquema de montagem do projeto.

<h3>Recursos necessários para execução do projeto</h3>

<h4>Software</h4>
<li>IDE Arduino. Download: https://www.arduino.cc/en/software;</li>
<li>Libs para funcionamento de componentes (ESP8266WiFi,DallasTemperature e One Wire). Download: https://www.arduino.cc/reference/en/libraries/;</li>

<h4>Hardware</h4>
<li>Arduino Uno;</li>
<li>Ponte H;</li>
<li>Motor DC 12V;</li>
<li>Protoboard;</li>
<li>Suporte para pilhas;</li>
<li>Node MCU;</li>
<li>Sensor de Temperatura DS18B20.</li>
<li>4 cabos Jumpers Macho X Macho</li>
<li>4 cabos Jumpers Macho X Fêmea</li>


<h2>Instruções para execução do Projeto</h2>

<li>1º - Clone o repositório;</li>
<li>2º - Abra o arquivo alimentador_peixes.ino em sua IDE Arduino;</li>
<li>3º - Importe as libs descristas acima em sua IDE. </li>

<strong>Observação</strong>: Caso esteja utilizando o Ubuntu e ao realizar o upload do software for apresentado algum erro relacionado ao /dev/ttyACM*, tente executar o seguinte comando no terminal "sudo chmod a+rw /dev/ttyACM*", após isso reiniciei sua IDE Arduino.
