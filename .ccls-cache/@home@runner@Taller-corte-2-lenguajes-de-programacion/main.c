#include <stdio.h>
#include <string.h>

#define students 3
#define limitNotes 3
#define pass "123456"

struct users {
  char *names;
  char *username;
  char *password;
  int type;
  float notes[limitNotes];
};
struct users usersList[4] = {
    {"Dario Profe", "profe", pass, 1},
    {"David", "david", pass, 2},
    {"Diego", "diego", pass, 2},
    {"Dana", "dana", pass, 2},
};

void addNotes(struct users currentUser) {
  int select = 0;
  int opts[students];
  for (int i = 0; i < students; ++i) {
    opts[i] = i;
  }
  do {
    printf("Para cual estudiante quiere ingresar notas:\n");
    for (int i = 0; i < 4; ++i) {
      if (usersList[i].type == 2) {
        printf("%d) Estudiante: %s\n", i + 1, usersList[i].names);
      }
    }
    scanf("%d", &select);
  } while (!opts[select]);
  select = select - 1;
  int iterator = 0;
  float note = 0;
  do {
    printf("Ingrese la nota (%d) para el estudiante '%s':\n", (iterator + 1),
           usersList[select].names);
    scanf("%f", &note);
    usersList[select].notes[iterator] = note;
    iterator++;
  } while (iterator < limitNotes);
  printf("Se agregaron las notas a: %s \n\n", usersList[select].names);
  printf("Se procede a cerrar la sesión '%s' \n\n", currentUser.names);
}

void actionStudents(struct users currentUser) {
  int opt;
  float average = 0;
  float max = 0;
  while (opt < 1 || opt > 3) {
    printf("Ingrese una opcion:\n");
    printf("1) Consultar notas\n");
    printf("2) Promedio notas\n");
    printf("3) Valor más alto notas\n");
    scanf("%d", &opt);
  }
  switch (opt) {
  case 1:
    printf("Sus notas son:\n");
    for (int i = 0; i < limitNotes; ++i) {
      printf("Nota #%d: %f\n", i + 1, currentUser.notes[i]);
    }
    break;
  case 2:
    for (int i = 0; i < limitNotes; ++i) {
      average = average + currentUser.notes[i];
    }
    printf("Su promedio es: %f\n", average);
    break;
  case 3:
    for (int i = 0; i < limitNotes; ++i) {
      if (max < currentUser.notes[i]) {
        max = currentUser.notes[i];
      }
    }
    printf("Su nota maxima es: %f\n", max);
    break;
  }
  printf("Gracias por consultar su información. Se procede a cerrar sesión. "
         "Gracias.\n\n");
}

void main() {
  printf("Colegio Casita Azul\n");
  char *datas[] = {"Nombre de usuario", "Contraseña"};
  char username[10];
  char password[10];
  for (int i = 0; i < 2; ++i) {
    printf("Ingrese su %s:\n", datas[i]);
    if (i == 0) {
      scanf("%s", username);
    } else {
      scanf("%s", password);
    }
  }
  for (int i = 0; i < 4; ++i) {
    struct users user = usersList[i];
    if (strcmp(user.username, username) == 0 &&
        strcmp(user.password, password) == 0) {
      printf("Hola: %s\n", user.names);
      switch (user.type) {
      case 1:
        printf("Tu role es 'profesor'\n");
        addNotes(user);
        break;
      case 2:
        printf("Tu role es 'estudiante'\n");
        actionStudents(user);
        break;
      }
      break;
    }
  }
  main();
}
