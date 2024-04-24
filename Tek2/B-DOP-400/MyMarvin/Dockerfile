FROM jenkins/jenkins:lts-jdk17

USER root

# Install system packages
RUN apt-get update -y \
    && apt-get upgrade -y \
    && apt-get install -y \
        build-essential \
        libcriterion-dev

USER jenkins

# Install plugins
RUN jenkins-plugin-cli --plugins cloudbees-folder \
                                 configuration-as-code \
                                 credentials \
                                 github \
                                 instance-identity \
                                 job-dsl \
                                 script-security \
                                 structs \
                                 role-strategy \
                                 ws-cleanup
