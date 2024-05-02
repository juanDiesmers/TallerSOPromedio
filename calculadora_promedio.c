/*
 * Autor: Juan Diego Palacios Toledo
 * Fecha: 2/05/2024
 *
 * Descripción:
 * Este programa crea una interfaz gráfica para abrir un archivo de texto,
 * leer y analizar los números en él, y calcular la suma y el promedio por columna.
 * Utiliza GTK+ para la GUI.
 *
 * Compilación:
 * gcc `pkg-config --cflags gtk+-3.0` -o analizador calculadora_promedio.c `pkg-config --libs gtk+-3.0`
 */

#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100  // Máximo de columnas soportadas

// Declaraciones de funciones
static void open_file(GtkWidget *widget, gpointer data);
static void analyze_file(const char *filename);

// Variables globales para la interfaz gráfica
static GtkWidget *window;
static GtkWidget *results_text;

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Configuración inicial de la ventana principal
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Archivo Analizador");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Contenedor vertical
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Botón para abrir el archivo
    GtkWidget *open_button = gtk_button_new_with_label("Abrir Archivo");
    g_signal_connect(open_button, "clicked", G_CALLBACK(open_file), NULL);
    gtk_box_pack_start(GTK_BOX(vbox), open_button, FALSE, FALSE, 0);

    // Área de texto con scroll para mostrar resultados
    results_text = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(results_text), FALSE);
    GtkWidget *scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(scrolled_window), results_text);
    gtk_box_pack_start(GTK_BOX(vbox), scrolled_window, TRUE, TRUE, 0);

    // Mostrar todos los componentes
    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

/*
 * Función open_file:
 * Abre un diálogo para seleccionar archivos y permite al usuario elegir un archivo de texto.
 * Después de seleccionar un archivo, invoca analyze_file para procesar el archivo.
 */
static void open_file(GtkWidget *widget, gpointer data) {
    GtkWidget *dialog = gtk_file_chooser_dialog_new("Open File",
                                                    GTK_WINDOW(window),
                                                    GTK_FILE_CHOOSER_ACTION_OPEN,
                                                    "_Cancel", GTK_RESPONSE_CANCEL,
                                                    "_Open", GTK_RESPONSE_ACCEPT,
                                                    NULL);
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_ACCEPT) {
        char *filename;
        GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
        filename = gtk_file_chooser_get_filename(chooser);
        analyze_file(filename);
        g_free(filename);
    }
    gtk_widget_destroy(dialog);
}

/*
 * Función analyze_file:
 * Abre y lee el archivo especificado, analiza los datos y calcula la suma y el promedio
 * de cada columna de números. Los resultados se muestran en la interfaz gráfica.
 */
static void analyze_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    char line[1024];
    int sums[MAX_COLUMNS] = {0};
    int counts[MAX_COLUMNS] = {0};
    int column_count = 0;

    // Leer línea por línea y procesar cada número
    while (fgets(line, sizeof(line), file)) {
        int col_index = 0;
        char *token = strtok(line, " \t\n");

        while (token != NULL) {
            int num;
            if (sscanf(token, "%d", &num) == 1) {
                if (col_index >= column_count) {
                    column_count = col_index + 1;
                }
                sums[col_index] += num;
                counts[col_index]++;
            }
            token = strtok(NULL, " \t\n");
            col_index++;
        }
    }

    fclose(file);

    // Actualizar el área de texto con los resultados calculados
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(results_text));
    gtk_text_buffer_set_text(buffer, "", 0);
    GtkTextIter end;
    gtk_text_buffer_get_end_iter(buffer, &end);

    char results[1024];
    for (int i = 0; i < column_count; i++) {
        if (counts[i] > 0) {
            double average = (double)sums[i] / counts[i];
            sprintf(results, "Columna %d: Suma = %d, Promedio = %.2f\n", i + 1, sums[i], average);
            gtk_text_buffer_insert(buffer, &end, results, -1);
        }
    }
}
