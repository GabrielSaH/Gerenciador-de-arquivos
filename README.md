# Repositório destinado a implementação de um gerenciador de processos

Os processos são um conceito fundamental em sistemas operacionais, representando a unidade básica de execução. 
Os processos desempenham um papel central no gerenciamento e execução de tarefas. 
- Principais conceitos relacionados a processos:

### 1. O Que é um Processo?
Um processo é uma instância de um programa em execução. Ele contém todas as informações necessárias para que um programa seja executado pelo sistema operacional. 
Isso inclui o código do programa, dados, estado atual, registradores, pilha de execução, ponteiros de memória e outros recursos associados.

### 2. Criação de Processos
A criação de processos ocorre de várias maneiras, como no carregamento de um programa pelo sistema operacional ou 
na geração de processos filhos a partir de processos pais (por exemplo, usando o sistema de chamadas `fork()` 
em sistemas UNIX). Durante a criação, o sistema operacional aloca recursos ao processo e define sua prioridade e estado inicial.

### 3. Estados dos Processos
Os processos podem estar em diferentes estados ao longo do seu ciclo de vida. Alguns dos estados mais comuns incluem:
- **Pronto (Ready)**: O processo está pronto para ser executado, aguardando a alocação da CPU.
- **Executando (Running)**: O processo está sendo executado pela CPU.
- **Bloqueado (Blocked)**: O processo está aguardando um evento, como entrada/saída ou um sinal.
- **Terminado (Terminated)**: O processo completou sua execução.

### 4. Escalonamento de Processos
O escalonamento é o mecanismo pelo qual o sistema operacional decide qual processo será executado pela CPU em um dado momento. 
Os algoritmos de escalonamento variam, com estratégias como escalonamento por prioridade, round-robin e tempo de execução 
restante mínimo (Shortest Remaining Time First).

### 5. Comunicação Entre Processos (IPC)
Os processos podem precisar se comunicar para realizar tarefas. Os mecanismos de comunicação entre processos (IPC) incluem sinais, 
pipes, semáforos, memórias compartilhadas e soquetes. Cada um desses mecanismos serve a diferentes necessidades, como sincronização, 
transmissão de dados ou troca de mensagens.

### 6. Sincronização e Concorrência
A sincronização é crucial para evitar condições de corrida e garantir a consistência dos dados quando múltiplos processos 
compartilham recursos. Técnicas como semáforos, mutexes e monitores são usadas para garantir acesso seguro a recursos compartilhados.

### 7. Terminação de Processos
Um processo pode ser terminado por várias razões: conclusão normal, erro fatal, intervenção do sistema operacional ou sinal externo. 
O sistema operacional precisa garantir que todos os recursos associados ao processo sejam liberados ao término.

### 8. Gestão de Recursos e Prioridades
Os processos podem ter prioridades para determinar a ordem de execução. Além disso, o sistema operacional gerencia recursos alocados 
aos processos, como memória, CPU, dispositivos de E/S e tempo de execução.

# Tópico 2 - Aprofundamento em conceitos chave
Se aprofundar nos aspectos relacionados aos processos implica explorar conceitos-chave do gerenciamento de processos, suas interações e 
detalhes específicos de como funcionam.

### 1. Estrutura de um Processo
Cada processo no sistema operacional tem uma estrutura que inclui informações essenciais para seu gerenciamento e execução. Essas informações 
geralmente incluem:

- **Espaço de Endereçamento**: Define a área de memória atribuída ao processo, consistindo de seções como segmento de código, segmento de dados, 
heap e pilha.

- **Contexto do Processo**: Contém registradores, ponteiros de pilha, contador de programa e outras informações críticas para retomar a execução do 
processo após uma interrupção ou troca de contexto.

- **Recursos Alocados**: Recursos como arquivos abertos, dispositivos de E/S e outras dependências.

### 2. Ciclo de Vida de um Processo
O ciclo de vida de um processo pode ser descrito em etapas:

- **Criação**: Um processo é criado por um sistema de chamadas como `fork()` ou por um sistema de gerenciamento de processos. 
O novo processo herda atributos do processo pai, mas pode ter algumas configurações específicas.

- **Execução**: O processo é executado pela CPU. Durante essa etapa, pode ser interrompido para dar lugar a outros processos, 
caso o sistema operacional use técnicas de escalonamento preemptivo.

- **Espera/Bloqueio**: Um processo pode ser bloqueado quando aguarda eventos externos, como entrada/saída ou sincronização com 
outros processos.

- **Encerramento**: O processo termina quando sua tarefa é concluída ou se encontra um erro fatal. O sistema operacional libera 
recursos alocados ao processo durante o encerramento.

### 3. Escalonamento de Processos
Os sistemas operacionais precisam decidir qual processo executar em cada momento. Para isso, usam algoritmos de escalonamento que 
consideram prioridades, tempo de execução e outros critérios. Alguns algoritmos comuns incluem:

- **Round-Robin**: Cada processo recebe um tempo limitado de execução (quantum) antes de ser substituído por outro processo.
- **Prioridade**: Processos com maior prioridade são executados antes dos de menor prioridade.
- **Curto Restante Primeiro**: Processos com menor tempo de execução restante são priorizados.

### 4. Comunicação Entre Processos (IPC)
Os processos precisam se comunicar para compartilhar informações e coordenar atividades. Existem várias técnicas de IPC, como:

- **Pipes e Named Pipes**: Para comunicação linear entre processos, com pipes nomeados permitindo comunicação entre processos não relacionados.
- **Sinais**: Usados para enviar notificações ou comandos simples entre processos.
- **Memória Compartilhada**: Permite que processos compartilhem dados diretamente em um espaço de memória comum.
- **Semáforos e Mutexes**: Usados para sincronização e gerenciamento de acesso a recursos compartilhados.

### 5. Sincronização e Concorrência
Para evitar condições de corrida e inconsistências, a sincronização é fundamental. Técnicas como semáforos, mutexes, monitores e locks garantem 
que os processos possam acessar recursos compartilhados de maneira segura.

### 6. Gerenciamento de Recursos
Os processos competem por recursos do sistema, como memória, CPU e dispositivos de E/S. O sistema operacional deve gerenciar esses recursos para 
evitar conflitos e garantir desempenho. Algumas estratégias incluem:

- **Alocação Dinâmica de Recursos**: O sistema operacional ajusta a alocação de recursos com base nas necessidades dos processos.
- **Políticas de Prioridade**: Os processos mais importantes ou prioritários recebem mais recursos.
