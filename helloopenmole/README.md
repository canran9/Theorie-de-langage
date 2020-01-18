# Moi

## Description

Veuillez regarder mon rapport [IMPORTANT.md.](https://gitlab.com/canran9/helloopenmole/edit/master/IMPORTANT.md)

Afin de réaliser au maximum l'automatisation de la chaîne de déploiement, j'ai décidé d'utiliser GitLab comme l'outil CI/CD.  
Mais GitLab Runner ne peut pas être installé dans le même serveur sur lequel GitLab est installé. Donc j'ai utiliser docker pour instancier GitLab et GitLab-runner.

De votre côté, vous avez sûrement un serveur pour déployer, donc j'ai git une version du projet où GitLab Runner est installé sur GNU/Linux.

## Différences 

+ Il y a seulement 3 variables au lieu de 5. Il n'y a plus CI_REGISTRY_IMAGE, CI_REGISTRY_PASSWORD et CI_REGISTRY_USER.
+ Il y a des changements ans les deux derniers stages build-docker et deployer dans le fichier `.gitlab-ci.yml`.
+ 
