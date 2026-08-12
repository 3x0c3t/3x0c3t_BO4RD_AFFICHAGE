#include "menu.h"
#include "settings.h"
#include "display.h"
#include "benchmark.h"

// ============================================================
// INITIALISATION
// ============================================================

void menuInit()
{
    drawInterface();
}

// ============================================================
// GESTION DU TOUCHER
// ============================================================

void menuHandleTouch(
    uint16_t x,
    uint16_t y
)
{
    // --------------------------------------------------------
    // Boutons benchmarks
    // --------------------------------------------------------

    for (uint8_t i = 0; i < BENCHMARK_COUNT; i++)
    {
        int buttonY =
            BENCHMARK_START_Y +
            i * (BENCHMARK_HEIGHT + BENCHMARK_SPACING);

        if (
            x >= BENCHMARK_X &&
            x <= BENCHMARK_X + BENCHMARK_WIDTH &&
            y >= buttonY &&
            y <= buttonY + BENCHMARK_HEIGHT
        )
        {
            benchmarkToggle(i);

            Serial.print("[MENU] ");
            Serial.print(benchmarkGetName(i));
            Serial.println(
                benchmarkIsSelected(i)
                ? " -> SELECTIONNE"
                : " -> DESELECTIONNE"
            );

            drawInterface();

            return;
        }
    }

    // --------------------------------------------------------
    // Bouton LANCER
    // --------------------------------------------------------

    if (
        x >= RUN_BUTTON_X &&
        x <= RUN_BUTTON_X + RUN_BUTTON_W &&
        y >= RUN_BUTTON_Y &&
        y <= RUN_BUTTON_Y + RUN_BUTTON_H
    )
    {
        Serial.println("[MENU] Lancement des benchmarks");

        drawStatus("Benchmarks en cours...");

        benchmarkRunSelected();

        drawInterface();

        return;
    }
}