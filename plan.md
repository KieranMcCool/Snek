---
title: Snek Requirements Spec
author: Kieran McCool
geometry: tmargin=0.75in
---

# Components

## Snek 'Object'

A source file allowing Snek representation and manipulation of Snek 
datastructure.

Requirements:

* Some method of creating a Snek instance.
* Some method of freeing a created Snek from memory
* Some method of adding a segment to the Snek for when it eats.
* Some method of moving the Snek in 4-Directions in Cartesian Space.

## Game Logic

* Snek must be initialised.
* Score set to zero
* As user input is received, Snek should react to it
    - Arrow keys/WASD Keys for control
    - p to pause
    - q to quit
* Should be a difficulty parameter set with command line argument determining 
  move speed of Snek/game.
* Food placed in random location not already occupied by Snek.

## Renderer

* Should be separate from game logic.
* Must be able to present user with an up-to-date representation of the game 
  state.
* User should have a visual representation of their Snek, a representation of 
  the food location and a score readout.
* Render at fixed rate or as needed (at the end of turn)?
    - Probably for this use case, as needed.

Adding **constraints** to a project restricts flexibility to narrow the 
parameters of the project.

Different constraint techniques in UML include:
* Adding multiplicities on relationships restrict the number of instances of a 
class that can be involved in an association
* Guards can be used on activity and sequence diagrams to control the flow of 
events
* Notes can be used to informally describe more complex constraints

OCL is a more formal way to express constraints.

We can express:
* **Invariants** - constraints that must always be true for a system, 
declared with `inv:`
* **Pre-conditions** - things that must be satisfied before operations 
are invoked, declared with `pre:`
* **Post-conditions** - things that must be satisfied before an 
operation terminates, declared with `post:`

## OCL Syntax
The types available in OCL are:
* Booleans
* Integers
* Real numbers
* Strings
* UML classes
* Collections of the above values

You can also add inline comments using `-- comment`.

You can put constraints directly on the UML diagram:


You can dereference attributes and associations within OCL, either 
within the context or the invariant itself:


Comparison operators in OCL are:
* Equality: `=`
* Not equal to: `<>`
* Less than / less than or equal to / greater than / greater than 
equal to: `> >= < <=`

> Note equality is a single `=` - not assignment like in many 
programming languages   

Operators available are:
* Arithmetic `+ - * /`
* Logical `and or not`
* Implications `implies`


An example showing some of these features is shown below

If you have an association with a multiplicity, you can have 
different types of collections, including sets, ordered sets and 
sequences.

To get all instances of a class in a model use 
`ClassName.allInstances()`.


You can check the `.size()` and if a collection `.isEmpty()`. You 
can access collections of elements of the collection themselves 
using the `->` symbol.


There are a variety of more complex properties for collections:


For a large example see the lecture notes for the last lecture.

