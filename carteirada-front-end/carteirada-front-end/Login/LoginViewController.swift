//
//  LoginViewController.swift
//  carteirada-front-end
//
//  Created by Robson Novato Lobao on 23/09/22.
//

import UIKit

class LoginViewController: UIViewController {

    @IBOutlet weak var loginButtonEddit: DefaultButton!
    
    @IBOutlet weak var emailTF: DefaultTextField!
    @IBOutlet weak var pwTF: DefaultTextField!
    
    var viewModel: LoginViewModel!
        
    override func viewDidLoad() {
        super.viewDidLoad()
        viewModel = LoginViewModel(delegate: self)
        pwField()
        loginButtonEddit.configure(whatsInside: "Logar")
    }
    @IBAction func registerButton(_ sender: Any) {
        let myViewController = Register2ViewController()
        myViewController.modalPresentationStyle = .fullScreen
        self.present(myViewController, animated: false, completion: nil)
    }
    
    private func pwField() {
        pwTF.isSecureTextEntry = true
    }

    @IBAction func loginButton(_ sender: Any) {
        viewModel.postLogUser(email: emailTF.text ?? "", password: pwTF.text ?? "")
    }
}

extension LoginViewController: ServiceDelegate {
    func dataSucess() {
        let alert = UIAlertController(title: "Sucesso", message: nil, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Continuar", style: .destructive, handler: {(action:UIAlertAction!) in
            self.dismiss(animated: false)
        }))
        self.present(alert, animated: true)
        UserDefaults.standard.set(true, forKey: "logado")
        UserDefaults.standard.set(emailTF.text, forKey: "email")
    }
        
    func dataFail(error: Error) {
        let alert = UIAlertController(title: "Erro", message: error.localizedDescription, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "Ok", style: .destructive, handler: nil))
        self.present(alert, animated: true)
    }
        
    func showLoad() {
        showSpinner(onView: view)
    }
        
    func removeLoad() {
        removeSpinner()
    }
}
