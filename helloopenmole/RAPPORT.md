# Avant de commencer


+ ## 1. S'assurer qu'on a le Java 8 JDK (aussi appelé 1.8)

    ```
    java -version
    javac -version
    ```

+ ## 2. Installer `sbt` sous Mac OS X: 
    
    ```
    brew install sbt
    ```

+ ## 3. Installer `Docker` sous Mac OS X:

    Cliquer sur le lien: <https://docs.docker.com/docker-for-mac/install/>


# [Etape 1] Le projet Scala en utilisant sbt


+ ## 1. Objectif

    Pour pouvoir générer une page web qui affiche "hello world" et l'écrire dans 
    un fichier HTML.

+ ## 2. Créer le sbt projet dans Intellij IDEA
    + ### 2.1. Télécharger et installer le plugin Scala

        Recherchez «Scala» dans le menu des plugins. 
  + ### 2.2. Créer un nouveau projet

        **Create new project** - **Scala** - **SBT**
  + ### 2.3. La structure du projet sbt

        Le projet sbt (build correct) contient le fichier `build.sbt`, *src* et  
        les répertoires *target*, modules.
  

+ ## 3. Add Depencies

    Dans le fichier `build.sbt`, on ajoute les deux librairies `ScalaTags` et `better-files`:

    ```scala
    libraryDependencies += "com.lihaoyi" %% "scalatags" % "0.8.2"
    libraryDependencies += "com.github.pathikrit" %% "better-files" % "3.8.0"
    ```

+ ## 4. Ecrire du code

    Dans le fichier `./src/main/scala/Index.scala`, 
        
    ```scala
    import scalatags.Text.all._
    import better.files._
    
    object Index {
      val htmlFrag: String = "<!DOCTYPE html>" + html(
        head(
          meta(charset := "utf-8"),
        ),
        body(
          h1("Hello world!1")
        )
      )
    
      def main(args: Array[String]): Unit = {
        println(htmlFrag)
        File("index.html").overwrite(htmlFrag)
      }
    }
    
    ```

+ ## 5. Utiliser sbt shell 

    Pour exécuter des commandes et des tasks sbt, pour exécuter et déboguer le projet.


# [Etape 2] Déploiement automatique en utilisant GitLab-CI + GitLab-Runner + Docker


+ ## 1. Description 
    
    Depuis GitLab 8.0, GitLab CI est déjà intégré dans GitLab.Donc pour réaliser le déploiement continu,il faut juste ajouter un fichier `.gitlab-ci.yml` et congigurer  
    un GitLab-Runner. Vue que Runner ne peut pas installé dans le même serveur sur lequel GitLab est installé, j'ai tout utiliser `docker` pour GitLab et GitLab-runner.  
    Étant donné que l'utilisation de docker est plus flexible, une machine peut créer plusieurs images de docker, tout en conservant l'isolement environnemental.

    <font color=green size=5>Veuillez regarder le fichier `README.md` pour que vous puissiez vérifier l'automatisation de déploiement.</font>   

+ ## 2. Installer et exécuter GitLab CE avec Docker
     + ### 2.1. Télécharger l'image GitLab  
    
        ```
        docker pull gitlab/gitlab-ce
        ```

  + ### 2.2.Exécuter l'instance GitLab

        
        sudo docker run -d \
            --hostname _0.0.0.0 \
            --name gitlab \
            --restart always \
            --publish 30001:22 --publish 30000:80 --publish 30002:443 \
            --volume $HOME/gitlab/data:/var/opt/gitlab \
            --volume $HOME/gitlab/logs:/var/log/gitlab \
            --volume $HOME/gitlab/config:/etc/gitlab \
        gitlab/gitlab-ce

   + ### 2.3. Configurer l'instance GitLab

        En utilisant la commande ci-dessus, on rédige le fichier de configuration GitLab en utilisant `vi`.
        
        ```
        sudo docker exec -it gitlab vi /etc/gitlab/gitlab.rb
        ```
        Les lignes à modifier:
        ```
        external_url 'http://0.0.0.0:30000' (Voir la partie 2.2)
        nginx['listen_port'] = 80
        ```

        Redémarrer GitLab en utilisant la commande:
        
        ```
        docker restart gitlab
        ```

   + ### 2.4. Créer un projet sur ce instance GitLab

        Vérifier que GitLab est disponible à l'adresse: http://0.0.0.0:30000
        
        Se connecter en changeant le mot de passe et s’identifier avec le compte root
        
        Créer le projet *HelloOpenMOLE*
        
        Y ajouter le code source en suivant les instructions GIT sur la page du projet

![](https://gitlab.com/canran9/helloopenmole/raw/master/IMAGE/1.png)


+ ## 3. Installer et inscrire un GitLab Runner 
    + ### 3.1. Pull l'image gitlab_runner

```
sudo docker pull gitlab/gitlab-runner:latest
```

   + ### 3.2. Ajouter gitlab-runner conteneur

```
sudo docker run -d --name gitlab-runner --restart always \
 -v /Users/Shared/gitlab-runner/config:/etc/gitlab-runner \
 -v /var/run/docker.sock:/var/run/docker.sock \
gitlab/gitlab-runner:latest
```

   + ### 3.3. Exécuter la register commande

```
sudo docker exec -it gitlab-runner gitlab-ci-multi-runner register
```


+ #### 3.3.1.  Taper l'URL de l'instance GitLab et le token obtenu 

On peut trouver ces deux informations dans la page du projet en cliquant sur **Settings** - **CI/CD** - **Runners** - **Expand**
            
![](https://gitlab.com/canran9/helloopenmole/raw/master/IMAGE/2.png)
```
Please enter the gitlab-ci coordinator URL:
# http://0.0.0.0:30000
```
            
```
Please enter the gitlab-ci token for this runner:
# 
```

+ ####        3.3.2.  Taper une description pour le Runnner et les tags liées au Runner


            
            Please enter the gitlab-ci description for this runner:
            
            
            
        
            Please enter the gitlab-ci tags for this runner (comma separated):
            
            

+ ####        3.3.3.  

            
            Whether to run untagged builds [true/false]:
            # true
            
            
            
            Please enter the executor: docker, parallels, shell, kubernetes, docker-ssh, ssh, virtualbox, docker+machine, docker-ssh+machine:
            # docker
        
            
        
            Please enter the default Docker image (e.g. ruby:2.6):
            # nginx:latest
            
            
            Enfin, j'ai réussi l'inscription de Runner.


+ ## 4. Configurer le fichier `.gitlab-ci.yml` 

    ```
    # 3 phases de construction
    stages:
      - build
      - build-docker
      - deploy
    
    # Exécuter les code scala et générer une fichier index.html
    build:
      stage: build
      image: mozilla/sbt:latest
      script:
        - sbt run
      artifacts:
        paths:
          - index.html
    
    #  Copier index.html dans nginx image, puis Build et push nginx image
    build-docker:
      stage: build-docker
      image: docker:stable
      services:
        - docker:dind
      before_script:
        - docker login -u $CI_REGISTRY_USER -p $CI_REGISTRY_PASSWORD $CI_REGISTRY
      script:
        - docker build --pull -t "$CI_REGISTRY_IMAGE" -f Dockerfile .
        - docker push "$CI_REGISTRY_IMAGE"
    
    # pull nginx image et l'éxecuter
    deploy-image:
      stage: deploy
      image: kroniak/ssh-client:latest
      before_script:
        - echo "$SSH_PRIVATE_KEY" | tr -d '\r' | ssh-add - > /dev/null
        - mkdir -p ~/.ssh
        - chmod 700 ~/.ssh
        - ssh-keyscan $PROD_SERVER_IP >> ~/.ssh/known_hosts
        - chmod 644 ~/.ssh/known_hosts
      script:
        - ssh -p $SSH_PORT root@$PROD_SERVER_IP "docker pull $CI_REGISTRY_IMAGE && docker stop \$(docker ps -aq) && docker rm \$(docker ps -aq) && docker run -d --restart=unless-stopped -p 30000:80 $CI_REGISTRY_IMAGE"
    ```

+ ## 5.   Compléter le fichier `Dockerfile`

    ```
    FROM nginx:latest
    COPY index.html /var/www/html
    RUN  ln -sf /dev/stdout /var/log/nginx/access.log && ln -sf /dev/stderr /var/log/nginx/error.log
    ```

+ ## 6. Créer un fichier `.gitignore`

+ ## 7. Configurer les variables 

    Dans le fichier `.gitlab-ci.yml`, on a utilisé 5 variables:
    
        CI_REGISTRY_IMAGE：Nom de docker image
        CI_REGISTRY_PASSWORD：Password sur https://0.0.0.0:30000
        CI_REGISTRY_USER：Nom de l'utilisateur sur https://0.0.0.0:30000
        PROD_SERVER_IP：Adresse IP du serveur de déploiement
        SSH_PORT：Port SSH de l'adresse IP du serveur de déploiement
        SSH_PRIVATE_KEY：Clé privée SSH sur le serveur de déploiement 
    
    On peut le définir dans la page du projet en cliquant sur **Settings** - **CI/CD** - **Variables** - **Expand**
        
    
    

    





















