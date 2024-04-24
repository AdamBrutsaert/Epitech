# MyMarvin

## Bonuses

- Github credentials
- Automatic mail sending
- Jenkins Agent
- Build in docker

## How to run

In order to run the project, you first need to fulfill the .env file :

```bash
cp .env.example .env
vim .env
```

Then, you just need to type the following commands in a shell :

```bash
docker compose build --no-cache
docker compose up -d
```

If you'd like to see logs, you can do :

```bash
docker compose logs --follow
```

## How to run with bonuses

In order to run the project with bonuses, you first need to fulfill the
.env file :

```bash
cp .env.bonus.example .env
vim .env
```

Then, you just need to type the following commands in a shell :

```bash
docker compose -f docker-compose.bonus.yml build --no-cache
docker compose -f docker-compose.bonus.yml up -d
```

If you'd like to see logs, you can do :

```bash
docker compose -f docker-compose.bonus.yml logs --follow
```
