up: down
	docker compose up --build

down:
	docker compose down --remove-orphans

build:
	docker compose build --no-cache
