### todo
- estabelecer macros para printf, vide test.c 
- freespace buffer `sprintf` com `strlen()` funciona bem
  

### details
- quantidade alocada em RAM eh bem diferente da contida em arquivos, ja que estou guardando em texto, para facilitar debug, posso visualmente verificar integridade dos dados
- `createEmptyPage()` aloca espaco extra para overflow, facilitando ordenamento e split
### pos code
- tentar solucao recursiva do promotion, so para sentir a dificuldade
