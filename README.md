# Computação Gráfica

## Transformações Geométricas no Triângulo utilizando o OpenGL.

<p>
<div style="display: inline-block;">

![C++](https://img.shields.io/badge/-C++-05122A?style=flat&logo=Cplusplus)&nbsp;
![Visual Studio Code](https://img.shields.io/badge/-Visual%20Studio%202022-05122A?style=flat&logo=visual-studio&logoColor=8702e6)&nbsp;

</p>

<p align="justify">

### 1. Gerando a `visualização` de um triângulo.

```
std::array<glm::vec3, 3> Triangle = {
  glm::vec3{-1.0f, -1.0f, 0.0f},
  glm::vec3{1.0f, -1.0f, 0.0f},
  glm::vec3{0.0f,  1.0f, 0.0f},
};
```

#### Imagem gerada sem as transformações aplicadas

![image](https://user-images.githubusercontent.com/84406892/196693471-9c066413-460f-4f98-ae20-1d06195d51b5.png)

### 2. Aplicando a transformação de `Translação`.
```
glTranslatef(.5, .3, 0);
```	
### 3. Aplicando a transformação de `Escala`.
```
glScalef(.2, .2, .2);
```	
### 4. Aplicando a transformação de `Rotação`.
```
glRotatef(45, 0, 0, 1);
```
### 5. Aplicando a transformação de `Reflexão`.
```
glScalef(-1, -1, -1);
```	

## Imagem gerada após as transformações serem aplicadas.

Note que houve translação do objeto, diminuição da escala, rotação e reflexão do mesmo.

![image](https://user-images.githubusercontent.com/84406892/196693765-687f4112-4dd2-4431-a030-587df78c36e2.png)

  
</p>

## Compilação e Execução

Tutorial detalhado através da [Wiki](https://github.com/phpdias/triangulo_transformacoes_geometricas/wiki/).

Necessário:  

- [OpenGL](https://github.com/phpdias/triangulo_transformacoes_geometricas/wiki/Configurando-o-Projeto#opengl).

- [CMake](https://github.com/phpdias/triangulo_transformacoes_geometricas/wiki/Configurando-o-Projeto#cmake).

- [Configuração básica de um projeto com OpenGL](https://github.com/phpdias/triangulo_transformacoes_geometricas/wiki/Configurando-o-Projeto#configura%C3%A7%C3%A3o-b%C3%A1sica-de-um-projeto-com-opengl).

- [Dependências](https://github.com/phpdias/triangulo_transformacoes_geometricas/wiki/Configurando-o-Projeto#depend%C3%AAncias).



# Contatos

<div style="display: inline-block;">

<a href="https://t.me/phpdias" target="_blank">
  <img align="center" src="https://img.shields.io/badge/-phpdias-05122A?style=flat&logo=telegram" alt="telegram"/>
</a>
  
<a href="https://linkedin.com/in/phpd" target="_blank">
  <img align="center" src="https://img.shields.io/badge/-phpd-05122A?style=flat&logo=linkedin" alt="linkedin"/>
</a>

<a style="color:black" href="mailto:phpdias@outlook.com?subject=[GitHub]%20Transformacoes%20Geometrica%20Triangulo">
 <img align="center" src="https://img.shields.io/badge/-phpdias@outlook.com-05122A?style=flat&logo=email" alt="email"/>
</a>

</div>




