# Abstrato

Trabalho de implementação de sistema de arquivo FAT16 para disciplina de Sistemas Operacionais.

Trabalho M3 - FAT16. Alunos: Larissa de Souza, Paulo Hermans e Vinícius Schütz Piva. Data: 25/06.

# Instruções de Compilação

### Linux

Este projeto foi feito para Linux somente. Usuários de Windows devem usar WSL.

O sistema deve ter um compilador GCC 11+, com suporte à C11, e GNU Make.

Para compilar, rode:

```
$ make resetimg obese16
```

Para executar, rode:
```
$ ./obese16 <COMANDO> [ARGUMENTOS] <DISCO>
```

### Windows

Veja [Como instalar o Linux no Windows com o WSL](https://learn.microsoft.com/pt-br/windows/wsl/install), por Microsoft.

# Implementação

Os seguintes comandos foram implementados:

1. Listar -- ls
2. Mover  -- mv

# Exemplos

Por exemplo, para listar os arquivos:

```
$ ./obese16 ls disk.img
```

Para mover um arquivo:

```
$ ./obese16 mv test.txt other.exe disk.img
```

# Guia Documentação

To be Written.

Veja `source/commands.c : void mv(FILE *fp, char *source, char* dest, struct fat_bpb *bpb)`.
