FROM python:3
RUN apt-get update \
    && apt-get install -y \
       bc \
       curl \
       sudo \
    && rm -rf /var/lib/apt/lists/*

## Fix https://stackoverflow.com/questions/34318554/java-lang-numberformatexception-on-eclipse-start
## And set a random password (846e02a00536464190bb15d9a27908ff) so that it is
## possible to sudo inside the container.
RUN groupadd -g 1000 jenkins \
    && useradd -lm -u 1000 -g 1000 jenkins \
    && adduser jenkins sudo \
    && (echo 'jenkins:846e02a00536464190bb15d9a27908ff' | chpasswd) \
    && mkdir -p /home/jenkins/workspace \
    && chown jenkins:jenkins /home/jenkins/workspace
