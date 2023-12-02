FROM maven:3.8.4-jdk-11-slim as builder
WORKDIR /usr/src/app
COPY . .
RUN mvn dependency:resolve
RUN mvn package

FROM openjdk:11-jre-slim
WORKDIR /usr/src/app/
COPY --from=builder /usr/src/app/target .
CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]
