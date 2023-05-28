//
//  LoginViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 23/09/22.
//

import UIKit
import FirebaseAuth

class LoginViewController: UIViewController {

    @IBOutlet weak var loginButtonEddit: DefaultButton!
    @IBOutlet weak var emailTF: DefaultTextField!
    @IBOutlet weak var pwTF: DefaultTextField!
    
    var auth: Auth?
        
    override func viewDidLoad() {
        super.viewDidLoad()
        pwField()
        loginButtonEddit.configure(whatsInside: "Logar")
        setupToolBarEmail()
        setupToolBarPW()
        self.auth = Auth.auth()
    }
    @IBAction func registerButton(_ sender: Any) {
        navigationController?.popViewController(animated: false)
    }
    
    private func pwField() {
        pwTF.isSecureTextEntry = true
    }

    @IBAction func loginButton(_ sender: Any) {
        let email: String = self.emailTF.text ?? ""
        let pw: String = self.pwTF.text ?? ""
        
        self.auth?.signIn(withEmail: email, password: pw, completion: { usuario, error in
            if error != nil {
                let alert = UIAlertController(title: "Erro", message: error.debugDescription, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Ok", style: .destructive, handler: nil))
                self.present(alert, animated: true)
            } else {
                let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
                alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
                    self.navigationController?.popToRootViewController(animated: true)
                }))
                self.present(alert, animated: true)
            }
        })
    }
    
    private func setupToolBarEmail() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        
        let closeButtonItemEmail = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardEmail))
        let nextButtonItemEmail = UIBarButtonItem(title: "próximo", style: .done, target: self, action: #selector(nextTextFieldEmail))
        keyboardToolbar.items = [flexBarButton, closeButtonItemEmail, nextButtonItemEmail]
        emailTF.inputAccessoryView = keyboardToolbar
    }
    
    private func setupToolBarPW() {
        let keyboardToolbar = UIToolbar()
        keyboardToolbar.sizeToFit()
        let flexBarButton = UIBarButtonItem(barButtonSystemItem: .flexibleSpace, target: nil, action: nil)
        let closeButtonItemEmail = UIBarButtonItem(title: "fechar", style: .done, target: self, action: #selector(closeKeyboardPW))
        keyboardToolbar.items = [flexBarButton, closeButtonItemEmail]
        pwTF.inputAccessoryView = keyboardToolbar
    }
    
    @objc func closeKeyboardEmail() {
        emailTF.endEditing(true)
    }
    
    @objc func closeKeyboardPW() {
        pwTF.endEditing(true)
    }
    
    @objc func nextTextFieldEmail() {
        emailTF.resignFirstResponder()
        pwTF.becomeFirstResponder()
    }
}
