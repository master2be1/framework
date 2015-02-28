<?hh
/**
 * @copyright   2010-2015, The Titon Project
 * @license     http://opensource.org/licenses/bsd-license.php
 * @link        http://titon.io
 */

/**
 * --------------------------------------------------------------
 *  Type Aliases
 * --------------------------------------------------------------
 *
 * Defines type aliases that are used by the console package.
 */

namespace Titon\Console {

    type RawInput = shape(
        'raw'   => string,
        'value' => string
    );
    type CommandMap = Map<string, Command>;
}