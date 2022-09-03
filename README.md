# checkpoint04
Protótipo de um sistema de identificação IoT, desenvolvido na disciplina de IoT.

# Nome do projeto

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

Um segundo fluxo Node-Red subscreve e publica o tópico, e em um DASHBOARD:
- exibe o valor da TAG e um registro das ultimas leituras
- exibe temperatura e umidade
- controla a posição do servo motor
- cadastra o email do usuário em um DB(SQLite) para receber alertas de temperatura e umidade

## Circuito eletrõnico

<img src="/circuito.png" width="550">

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

Adicione o link para assistir ao vídeo do projeto funcionando.

[Link para o video youtube](https://www.youtube.com/watch?v=xva71wynxS0)


### Referências 

* [mastering-markdown](https://guides.github.com/features/mastering-markdown/)
* [Basic writing and formatting syntax](https://docs.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)
