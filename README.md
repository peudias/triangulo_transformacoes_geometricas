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
  
</p>

## Compilação e Execução

Informações mais detalhadas através da [Wiki](https://github.com/phpdias/triangulo_transformacoes_geometricas/wiki/).

Necessário o [OpenGL](https://github.com/phpdias/triangulo_transformacoes_geometricas/wiki/Configurando-o-Projeto).




# Contatos

<div style="display: inline-block;">

<a href="https://t.me/phpdias" target="_blank">
  <img align="center" src="https://img.shields.io/badge/-phpdias-05122A?style=flat&logo=telegram" alt="linkedin"/>
</a>
  
<a href="https://linkedin.com/in/phpd" target="_blank">
  <img align="center" src="https://img.shields.io/badge/-phpd-05122A?style=flat&logo=linkedin" alt="linkedin"/>
</a>

<a style="color:black" href="mailto:phpdias@outlook.com?subject=[GitHub]%20Source%20Dynamic%20Lists">
 <img align="center" src="https://img.shields.io/badge/-phpdias@outlook.com-05122A?style=flat&logo=email" alt="linkedin"/>
</a>

</div>




