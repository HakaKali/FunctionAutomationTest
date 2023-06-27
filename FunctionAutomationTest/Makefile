CC = gcc
CFLAGS = -Wall -Wextra -std=c99
BINDIR = bin
TESTDIR = test_files

all: $(BINDIR)/project

$(BINDIR)/project: $(BINDIR)/main.o $(BINDIR)/utils.o | $(BINDIR)
	@$(CC) $(CFLAGS) $^ -o $@

$(BINDIR)/main.o: src/main.c src/project.h | $(BINDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR)/utils.o: src/utils.c src/project.h | $(BINDIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(BINDIR):
	@mkdir -p $(BINDIR)

clean:
	@rm -f $(BINDIR)/*.o $(BINDIR)/project

run: $(BINDIR)/project | $(TESTDIR)
	@cd $(BINDIR) && ./project ../$(TESTDIR)
	@mv $(BINDIR)/test_cases.txt $(TESTDIR)/test_cases.txt
	@mv $(BINDIR)/test_results.txt $(TESTDIR)/test_results.txt


$(TESTDIR):
	@mkdir -p $(TESTDIR)
