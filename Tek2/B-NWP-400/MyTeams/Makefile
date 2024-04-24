##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

NAMES := my protocol server cli

all:
	@for name in $(NAMES); do \
		$(MAKE) -s -C $$name; \
	done

clean:
	@for name in $(NAMES); do \
		$(MAKE) -s -C $$name clean; \
	done
	@rm -rf build

fclean:
	@for name in $(NAMES); do \
		$(MAKE) -s -C $$name fclean; \
	done
	@rm -rf build

re:
	@for name in $(NAMES); do \
		$(MAKE) -s -C $$name re; \
	done

release:
	@for name in $(NAMES); do \
		$(MAKE) -s -C $$name release; \
	done

debug:
	@for name in $(NAMES); do \
		$(MAKE) -s -C $$name debug; \
	done

tests: debug
	@for name in $(NAMES); do \
		$(MAKE) -s -C $$name tests; \
	done

tests_run: tests
	@FAILED=0; for name in $(NAMES); do \
		$(MAKE) -s -C $$name tests_run; \
		if [ $$? -ne 0 ]; then \
			FAILED=1; \
		fi; \
	done; \
	exit $$FAILED

.PHONY: all clean fclean re release debug tests tests_run
