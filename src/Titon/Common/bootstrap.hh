<?hh
/**
 * @copyright   2010-2015, The Titon Project
 * @license     http://opensource.org/licenses/bsd-license.php
 * @link        http://titon.io
 */

/**
 * --------------------------------------------------------------
 *  Custom Types
 * --------------------------------------------------------------
 *
 * Defines type aliases that are used by the common package.
 */

namespace Titon\Common {
    type CacheMap = Map<string, mixed>;

    // Macros
    type MacroCallback = (function(...): mixed);
    type MacroContainer = Map<string, MacroMap>;
    type MacroMap = Map<string, MacroCallback>;
}

/**
 * --------------------------------------------------------------
 *  Helper Functions
 * --------------------------------------------------------------
 *
 * Defines global helper functions for common use cases.
 */

namespace {
    use Titon\Common\Exception\MissingFileException;

    /**
     * Include a file at a given path and return the response of the include.
     *
     * @param string $path
     * @return array<Tk, Tv>
     * @throws \Titon\Common\Exception\MissingFileException
     */
    function include_file<Tk, Tv>(string $path): array<Tk, Tv> {
        if (!file_exists($path)) {
            throw new MissingFileException(sprintf('File %s does not exist', $path));
        }

        return include $path;
    }

    /**
     * Very low level function for loading a template with optional variables and rendering the result.
     *
     * @param string $path
     * @param array <string, Tv> $variables
     * @return string
     * @throws \Titon\Common\Exception\MissingFileException
     */
    function render_template<Tv>(string $path, array<string, Tv> $variables = []): string {
        if (!file_exists($path)) {
            throw new MissingFileException(sprintf('Template %s does not exist', $path));
        }

        extract($variables, EXTR_OVERWRITE);
        ob_start();

        include $path;

        return ob_get_clean();
    }

}
