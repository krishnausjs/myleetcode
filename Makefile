.PHONY: clean All

All:
	@echo "----------Building project:[ 2_add_two_numbers - Debug ]----------"
	@cd "2_add_two_numbers" && "$(MAKE)" -f  "2_add_two_numbers.mk"
clean:
	@echo "----------Cleaning project:[ 2_add_two_numbers - Debug ]----------"
	@cd "2_add_two_numbers" && "$(MAKE)" -f  "2_add_two_numbers.mk" clean
