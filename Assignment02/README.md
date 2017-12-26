=== Assignment ===
------------
###Assignment
Pizza Shop:

Write a program that calculates the prices for pizzas and tells the pizza shop owner if they have enough ingredients to fill the order.


You are provided 3 files: recipes.json, ingredients.json and prices.json. These are all example files and your code must work with any kind of such file that matches the object syntax.

Each file contains a list of objects whose schema is defined below.

Prices contains the ids and prices for each price.

Ingredients contains the names, stock counts (total available quantity) and priceTypes for each ingredient - this is the amount of ingredients available for you during one program run. Ingredient priceType is matched with a Price from prices.json file (match them by their id number).

Recipes contains pizzas with ingredients - these are the same ingredients as in ingredients.json file (match them by their name).


Your program must read all .json files and provide console input where you can enter a pizza (pizza name) to be made. You can make any number of pizzas (at least until there are enough ingredients left).
____

###Program usage:

1) Console asks for pizza name to be made

2) User enters pizza name

3a) When the pizza can be made (is made):

Print to console the total price of the pizza.

Ingredients used must be taken off your stock.

3b) When the pizza cannot be made:

Print out which ingredients are missing and how many.

4) --Return to step 1.
___

###Datatypes (schema):

####Pizza:

name - string

ingredients - list of strings
Ingredient:

name - string

quantity - integer

priceType - integer

####Price:

id - integer

price - double 
