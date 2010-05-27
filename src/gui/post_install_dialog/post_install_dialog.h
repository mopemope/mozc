// Copyright 2010, Google Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are
// met:
//
//     * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above
// copyright notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
//     * Neither the name of Google Inc. nor the names of its
// contributors may be used to endorse or promote products derived from
// this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef MOZC_GUI_POST_INSTALL_DIALOG_H_
#define MOZC_GUI_POST_INSTALL_DIALOG_H_

#include "gui/post_install_dialog/ui_post_install_dialog.h"
#include "base/base.h"

namespace mozc {

class UserDictionaryStorage;

namespace gui {

// Shows additional information to the user after installation.
// This dialog also set Mozc as the default IME if it is closed
// with the check box marekd.
class PostInstallDialog : public QDialog,
                          private Ui::PostInstallDialog {
  Q_OBJECT;

 public:
  PostInstallDialog();
  virtual ~PostInstallDialog();

  // Returns true if log off is required to use Mozc.
  bool logoff_required();

  // Shows the help page by opening it with the default browser.
  // Returns true if page is successfully opened by the browser.
  static bool ShowHelpPageIfRequired();

 protected slots:
  virtual void OnLogoffNow();
  virtual void OnLogoffLater();
  virtual void OnOk();
  virtual void reject();

 private:
  // - Sets Mozc as the default IME if the check box on the
  //   dialog is marked.
  // - Imports MS-IME's user dictionary to Mozc' dictionary if
  //   the checkbox on the dialog is marked.
  void ApplySettings();

  // Returns true if showing the help page is required.
  static bool IsShowHelpPageRequired();

  bool logoff_required_;

  scoped_ptr<UserDictionaryStorage> storage_;
};
}  // namespace gui
}  // namespace mozc
#endif  // MOZC_GUI_POST_INSTALL_DIALOG_H_