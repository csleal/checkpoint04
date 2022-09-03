# checkpoint04
Protótipo de um sistema de identificação IoT, desenvolvido na disciplina de IoT.

**nome dos alunos:**

* Carlos Rithyellen de Souza Leal - RM 89052
* Renan da Silva Ramos – RM 89339

**Turma:** 2TDSA

**Ano:** 2° ano, 2022

## Objetivo / descrição do Projeto

Sistema embarcado em uma Raspberry Pi capaz de coletar a identificação da TAG RFID, coletar dados do sensor DHT11 (Temperatura e Umidade) com o Arduino (ARDUINO1) e comunica com o arduino (ARDUINO2) no formato JSON para realizar o sistema de posição do servo motor e envia utilizando formato JSON para um fluxo Node-Red que realiza diversas funções: 
- publica e subscreve em um tópico utilizando o protocolo MQTT.
- Notifica o usuário via telegram(Qualquer alteração na posição do servo motor e a leitura da TAG RFID).
- Notifica via email (Se a umidade estiver abaixo de 50% ou a temperatura estiver acima de 30°C.). 

Um segundo fluxo Node-Red rodando na Cloud da IBM subscreve e publica o tópico, e em um DASHBOARD:
- exibe o valor da TAG e um registro das ultimas leituras
- exibe temperatura e umidade
- controla a posição do servo motor
- cadastra o email do usuário em um DB(SQLite) para receber alertas de temperatura e umidade

## Circuito eletrônico

<img src="/circuito.png">

## Dashboard

<img src="/dashboard.png">

## Diagrama do projeto

Adicione uma ou mais fotos do projeto, pode ser uma imagem da arquitetura, do circuito eletrônico do Flow desenvolvido. 

<img src="/imagem.jpg" width="550">


## Como usar 

Explique como rodar o seu projeto. Quais programas instalar, como configurar... 

* Pode ser utilizado marcadores
* Para ajudar na formatação

Ou qualquer outra tabulação:

- [x] Youtube
- [ ] Facebook 
- [x] Instagram

Pode adicionar algum trecho de código, por exemplo para clonar esse repositório:

    cd /home/iot
    git clone https://github.com/arnaldojr/templatenac
    cd templatenac
    ls


## Link de vídeo demonstração

Vídeo de explicação do projeto e funcionamento.

[Link para o video youtube](https://www.youtube.com/watch?v=xva71wynxS0)


### Referências 

* [Aulas do Professor Arnaldo](https://arnaldojr.github.io/IoT/)
* [Como usar com Arduino – KIT RFID MFRC522](https://blogmasterwalkershop.com.br/arduino/como-usar-com-arduino-kit-rfid-mfrc522)
* [TEMPO SEM DELAY? CONHEÇA O MILLIS!](https://www.youtube.com/watch?v=rkicyLRCkHI)
* [Working With JSON Data in Node Red](https://www.youtube.com/watch?v=24ZY3CEsiow)
* [Node-Red -How to Send Email and SMS Notifications](https://www.youtube.com/watch?v=rokLM4ZsMJQ)
* [CONTROLE DE SERVO MOTOR VIA SERIAL | Curso de Arduino #211](https://www.youtube.com/watch?v=o2RVatVYCF)
* [Steve Cope - Node-Red Example Flows](https://stevesnoderedguide.com/node-red-example-flows)
